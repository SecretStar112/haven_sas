#' Read and write Stata DTA files
#'
#' @description
#' Currently haven can read and write logical, integer, numeric, character
#' and factors. See [labelled()] for how labelled variables in
#' Stata are handled in R.
#'
#' Character vectors will be stored as `strL` if any components are
#' `strl_threshold` bytes or longer (and `version` >= 13); otherwise they will
#' be stored as the appropriate `str#`.
#'
#' @section Character encoding:
#' Prior to Stata 14, files did not declare a text encoding, and the
#' default encoding differed across platforms. If `encoding = NULL`,
#' haven assumes the encoding is windows-1252, the text encoding used by
#' Stata on Windows. Unfortunately Stata on Mac and Linux use a different
#' default encoding, "latin1". If you encounter an error such as
#' "Unable to convert string to the requested encoding", try
#' `encoding = "latin1"`
#'
#' For Stata 14 and later, you should not need to manually specify `encoding`
#' value unless the value was incorrectly recorded in the source file.
#'
#' @inheritParams readr::datasource
#' @inheritParams read_spss
#' @param encoding The character encoding used for the file. Generally,
#'   only needed for Stata 13 files and earlier. See Encoding section
#'   for details.
#' @return A tibble, data frame variant with nice defaults.
#'
#'   Variable labels are stored in the "label" attribute of each variable.
#'   It is not printed on the console, but the RStudio viewer will show it.
#'
#'   If a dataset label is defined in Stata, it will stored in the "label"
#'   attribute of the tibble.
#'
#'   `write_dta()` returns the input `data` invisibly.
#' @export
#' @examples
#' path <- system.file("examples", "iris.dta", package = "haven")
#' read_dta(path)
#'
#' tmp <- tempfile(fileext = ".dta")
#' write_dta(mtcars, tmp)
#' read_dta(tmp)
#' read_stata(tmp)
read_dta <- function(file, encoding = NULL, col_select = NULL, skip = 0, n_max = Inf, .name_repair = "unique") {
  if (is.null(encoding)) {
    encoding <- ""
  }

  cols_skip <- skip_cols(read_dta, {{ col_select }}, file, encoding)
  n_max <- validate_n_max(n_max)

  spec <- readr::datasource(file)
  switch(class(spec)[1],
    source_file = df_parse_dta_file(spec, encoding, cols_skip, n_max, skip, name_repair = .name_repair),
    source_raw = df_parse_dta_raw(spec, encoding, cols_skip, n_max, skip, name_repair = .name_repair),
    cli_abort("This kind of input is not handled.")
  )
}

#' @export
#' @rdname read_dta
read_stata <- read_dta

#' @export
#' @rdname read_dta
#' @param version File version to use. Supports versions 8-15.
#' @param label Dataset label to use, or `NULL`. Defaults to the value stored in
#'   the "label" attribute of `data`. Must be <= 80 characters.
#' @param strl_threshold Any character vectors with a maximum length greater
#'   than `strl_threshold` bytes will be stored as a long string (strL) instead
#'   of a standard string (str#) variable if `version` >= 13. This defaults to
#'   2045, the maximum length of str# variables. See the Stata [long
#'   string](https://www.stata.com/features/overview/long-strings/)
#'   documentation for more details.
#' @param adjust_tz Stata, SPSS and SAS do not have a concept of time zone,
#'   and all [date-time] variables are treated as UTC. `adjust_tz` controls
#'   how the timezone of date-time values is treated when writing.
#'
#'   * If `TRUE` (the default) the timezone of date-time values is ignored, and
#'   they will display the same in R and Stata/SPSS/SAS, e.g.
#'   `"2010-01-01 09:00:00 NZDT"` will be written as `"2010-01-01 09:00:00"`.
#'   Note that this changes the underlying numeric data, so use caution if
#'   preserving between-time-point differences is critical.
#'   * If `FALSE`, date-time values are written as the corresponding UTC value,
#'   e.g. `"2010-01-01 09:00:00 NZDT"` will be written as
#'   `"2009-12-31 20:00:00"`.
write_dta <- function(data, path, version = 14, label = attr(data, "label"), strl_threshold = 2045, adjust_tz = TRUE) {
  data_out <- validate_dta(data, version = version)
  validate_dta_label(label)

  if (isTRUE(adjust_tz)) {
    data_out <- adjust_tz(data_out)
  }

  write_dta_(
    data_out,
    normalizePath(path, mustWork = FALSE),
    version = stata_file_format(version),
    label = label,
    strl_threshold = validate_strl_threshold(strl_threshold)
  )

  invisible(data)
}

stata_file_format <- function(version, call = caller_env()) {
  stopifnot(is.numeric(version), length(version) == 1)
  version <- as.integer(version)

  if (version == 15L) {
    119
  } else if (version == 14L) {
    118
  } else if (version == 13L) {
    117
  } else if (version == 12L) {
    115
  } else if (version %in% c(10L, 11L)) {
    114
  } else if (version %in% c(8L, 9L)) {
    113
  } else {
    cli_abort("Stata version {.val {version}} is not currently supported.", call = call)
  }
}

validate_strl_threshold <- function(strl_threshold, call = caller_env()) {
  stopifnot(is.numeric(strl_threshold), length(strl_threshold) == 1)

  if (strl_threshold < 0 || strl_threshold > 2045) {
    2045
  } else {
    strl_threshold
  }
}

validate_dta <- function(data, version, call = caller_env()) {
  stopifnot(is.data.frame(data))

  # Check variable names
  bad_name <- !grepl("^[A-Za-z_]{1}[A-Za-z0-9_]+$", names(data))
  bad_length <- nchar(names(data)) > 32
  bad_vars <- if (version >= 14) bad_length else bad_length | bad_name
  if (any(bad_vars)) {
    cli_abort(
      c(
        "Variables in {.arg data} must have valid Stata variable names.",
        x = "Problems: {.var {var_names(data, bad_vars)}}"
      ),
      call = call
    )
  }

  # Check double vectors can only have labelled integers
  bad_labels <- vapply(data, has_non_integer_labels, logical(1))
  if (any(bad_labels)) {
    cli_abort(
      c(
        "Stata only supports labelling with integer variables.",
        x = "Problems: {.var {var_names(data, bad_labels)}}"
      ),
      call = call
    )
  }
  invisible(data)
}

validate_dta_label <- function(label, call = caller_env()) {
  if (!is.null(label)) {
    stopifnot(is.character(label), length(label) == 1)

    if (nchar(label) > 80) {
      cli_abort("{.arg label} must be 80 characters or fewer.", call = call)
    }
  }
}



# helpers -----------------------------------------------------------------

has_non_integer_labels <- function(x) {
  if (is.null(attr(x, "labels"))) {
    return(FALSE)
  }

  if (!is.labelled(x)) {
    return(FALSE)
  }

  if (!is.double(x)) {
    return(FALSE)
  }

  !is_integerish(attr(x, "labels"))
}
# Adapted from rlang
is_integerish <- function(x) {
  if (!typeof(x) %in% c("double", "integer")) {
    return(FALSE)
  }

  missing_elts <- is.na(x)
  finite_elts <- is.finite(x) | missing_elts
  if (!all(finite_elts)) {
    return(FALSE)
  }

  x_finite <- x[finite_elts & !missing_elts]
  all(x_finite == as.integer(x_finite))
}
