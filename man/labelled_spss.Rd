% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/labelled_spss.R
\name{labelled_spss}
\alias{labelled_spss}
\title{Labelled vectors for SPSS}
\usage{
labelled_spss(
  x = double(),
  labels = NULL,
  na_values = NULL,
  na_range = NULL,
  label = NULL
)
}
\arguments{
\item{x}{A vector to label. Must be either numeric (integer or double) or
character.}

\item{labels}{A named vector or \code{NULL}. The vector should be the same type
as \code{x}. Unlike factors, labels don't need to be exhaustive: only a fraction
of the values might be labelled.}

\item{na_values}{A vector of values that should also be considered as missing.}

\item{na_range}{A numeric vector of length two giving the (inclusive) extents
of the range. Use \code{-Inf} and \code{Inf} if you want the range to be
open ended.}

\item{label}{A short, human-readable description of the vector.}
}
\description{
This class is only used when \code{user_na = TRUE} in
\code{\link[=read_sav]{read_sav()}}. It is similar to the \code{\link[=labelled]{labelled()}} class
but it also models SPSS's user-defined missings, which can be up to
three distinct values, or for numeric vectors a range.
}
\examples{
x1 <- labelled_spss(1:10, c(Good = 1, Bad = 8), na_values = c(9, 10))
is.na(x1)

x2 <- labelled_spss(
  1:10,
  c(Good = 1, Bad = 8),
  na_range = c(9, Inf),
  label = "Quality rating"
)
is.na(x2)

# Print data and metadata
x2
}
