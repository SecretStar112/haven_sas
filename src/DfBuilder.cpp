#include <Rcpp.h>
using namespace Rcpp;

extern "C" {
  #include "readstat.h"
}

class DfBuilder {
  int nrows_, ncols_;
  List output_;
  CharacterVector names_;

public:
  DfBuilder(): nrows_(0), ncols_(0) {
  }

  int info(int obs_count, int var_count) {
    nrows_ = obs_count;
    ncols_ = var_count;

    Rcout << nrows_ << "/" << ncols_ << "\n";

    output_ = List(ncols_);
    names_ = CharacterVector(ncols_);
    return 0;
  }

  int variable(int index, const char *var_name,
               const char *var_format,
               const char *var_label,
               const char *val_labels,
               readstat_types_t type, size_t max_len) {

    names_[index] = var_name;

    switch(type) {
    case READSTAT_TYPE_LONG_STRING:
    case READSTAT_TYPE_STRING:
    case READSTAT_TYPE_CHAR:
      output_[index] = CharacterVector(nrows_);
      break;
    case READSTAT_TYPE_INT16:
    case READSTAT_TYPE_INT32:
      output_[index] = IntegerVector(nrows_);
      break;
    case READSTAT_TYPE_FLOAT:
    case READSTAT_TYPE_DOUBLE:
      output_[index] = NumericVector(nrows_);
      break;
    }

    return 0;
  }

  int value(int obs_index, int var_index, void *value,
            readstat_types_t type) {

    return 0;
  }

  List output() {
    output_.attr("names") = names_;
    output_.attr("class") = CharacterVector::create("tbl_df", "data.frame");
    output_.attr("row.names") = IntegerVector::create(NA_INTEGER, -nrows_);

    return output_;
  }

};

int dfbuilder_info(int obs_count, int var_count, void *ctx) {
  return ((DfBuilder*) ctx)->info(obs_count, var_count);
}
int dfbuilder_variable(int index, const char *var_name, const char *var_format,
                       const char *var_label, const char *val_labels,
                       readstat_types_t type, size_t max_len,
                       void *ctx) {

  return ((DfBuilder*) ctx)->variable(index, var_name, var_format, var_label,
    val_labels, type, max_len);
}
int dfbuilder_value(int obs_index, int var_index, void *value,
                    readstat_types_t type, void *ctx) {

  return ((DfBuilder*) ctx)->value(obs_index, var_index, value, type);
}

// [[Rcpp::export]]
List sas7bdat_df(std::string filename) {
  DfBuilder* builder = new DfBuilder();

  int result = parse_sas7bdat(
    filename.c_str(),
    builder,
    dfbuilder_info,
    dfbuilder_variable,
    dfbuilder_value
  );

  List output = builder->output();
  delete builder;

  if (result != 0) {
    stop("Failed to parse %s (%i)", filename, result);
  }

  return output;
}
