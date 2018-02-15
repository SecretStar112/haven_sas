// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "haven_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// df_parse_sas_file
List df_parse_sas_file(Rcpp::List spec_b7dat, Rcpp::List spec_b7cat, std::string encoding, std::string catalog_encoding, std::vector<std::string> cols_only);
RcppExport SEXP _haven_df_parse_sas_file(SEXP spec_b7datSEXP, SEXP spec_b7catSEXP, SEXP encodingSEXP, SEXP catalog_encodingSEXP, SEXP cols_onlySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec_b7dat(spec_b7datSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type spec_b7cat(spec_b7catSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< std::string >::type catalog_encoding(catalog_encodingSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type cols_only(cols_onlySEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_sas_file(spec_b7dat, spec_b7cat, encoding, catalog_encoding, cols_only));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_sas_raw
List df_parse_sas_raw(Rcpp::List spec_b7dat, Rcpp::List spec_b7cat, std::string encoding, std::string catalog_encoding, std::vector<std::string> cols_only);
RcppExport SEXP _haven_df_parse_sas_raw(SEXP spec_b7datSEXP, SEXP spec_b7catSEXP, SEXP encodingSEXP, SEXP catalog_encodingSEXP, SEXP cols_onlySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec_b7dat(spec_b7datSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type spec_b7cat(spec_b7catSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< std::string >::type catalog_encoding(catalog_encodingSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type cols_only(cols_onlySEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_sas_raw(spec_b7dat, spec_b7cat, encoding, catalog_encoding, cols_only));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_xpt_file
List df_parse_xpt_file(Rcpp::List spec);
RcppExport SEXP _haven_df_parse_xpt_file(SEXP specSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_xpt_file(spec));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_xpt_raw
List df_parse_xpt_raw(Rcpp::List spec);
RcppExport SEXP _haven_df_parse_xpt_raw(SEXP specSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_xpt_raw(spec));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_dta_file
List df_parse_dta_file(Rcpp::List spec, std::string encoding);
RcppExport SEXP _haven_df_parse_dta_file(SEXP specSEXP, SEXP encodingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_dta_file(spec, encoding));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_dta_raw
List df_parse_dta_raw(Rcpp::List spec, std::string encoding);
RcppExport SEXP _haven_df_parse_dta_raw(SEXP specSEXP, SEXP encodingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_dta_raw(spec, encoding));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_sav_file
List df_parse_sav_file(Rcpp::List spec, std::string encoding, bool user_na);
RcppExport SEXP _haven_df_parse_sav_file(SEXP specSEXP, SEXP encodingSEXP, SEXP user_naSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< bool >::type user_na(user_naSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_sav_file(spec, encoding, user_na));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_sav_raw
List df_parse_sav_raw(Rcpp::List spec, std::string encoding, bool user_na);
RcppExport SEXP _haven_df_parse_sav_raw(SEXP specSEXP, SEXP encodingSEXP, SEXP user_naSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< bool >::type user_na(user_naSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_sav_raw(spec, encoding, user_na));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_por_file
List df_parse_por_file(Rcpp::List spec, std::string encoding, bool user_na);
RcppExport SEXP _haven_df_parse_por_file(SEXP specSEXP, SEXP encodingSEXP, SEXP user_naSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< bool >::type user_na(user_naSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_por_file(spec, encoding, user_na));
    return rcpp_result_gen;
END_RCPP
}
// df_parse_por_raw
List df_parse_por_raw(Rcpp::List spec, std::string encoding, bool user_na);
RcppExport SEXP _haven_df_parse_por_raw(SEXP specSEXP, SEXP encodingSEXP, SEXP user_naSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type spec(specSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< bool >::type user_na(user_naSEXP);
    rcpp_result_gen = Rcpp::wrap(df_parse_por_raw(spec, encoding, user_na));
    return rcpp_result_gen;
END_RCPP
}
// write_sav_
void write_sav_(List data, std::string path, bool compress);
RcppExport SEXP _haven_write_sav_(SEXP dataSEXP, SEXP pathSEXP, SEXP compressSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< bool >::type compress(compressSEXP);
    write_sav_(data, path, compress);
    return R_NilValue;
END_RCPP
}
// write_dta_
void write_dta_(List data, std::string path, int version);
RcppExport SEXP _haven_write_dta_(SEXP dataSEXP, SEXP pathSEXP, SEXP versionSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< int >::type version(versionSEXP);
    write_dta_(data, path, version);
    return R_NilValue;
END_RCPP
}
// write_sas_
void write_sas_(List data, std::string path);
RcppExport SEXP _haven_write_sas_(SEXP dataSEXP, SEXP pathSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    write_sas_(data, path);
    return R_NilValue;
END_RCPP
}
// write_xpt_
void write_xpt_(List data, std::string path, int version, std::string name);
RcppExport SEXP _haven_write_xpt_(SEXP dataSEXP, SEXP pathSEXP, SEXP versionSEXP, SEXP nameSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type data(dataSEXP);
    Rcpp::traits::input_parameter< std::string >::type path(pathSEXP);
    Rcpp::traits::input_parameter< int >::type version(versionSEXP);
    Rcpp::traits::input_parameter< std::string >::type name(nameSEXP);
    write_xpt_(data, path, version, name);
    return R_NilValue;
END_RCPP
}

RcppExport SEXP is_tagged_na_(SEXP, SEXP);
RcppExport SEXP na_tag_(SEXP);
RcppExport SEXP tagged_na_(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_haven_df_parse_sas_file", (DL_FUNC) &_haven_df_parse_sas_file, 5},
    {"_haven_df_parse_sas_raw", (DL_FUNC) &_haven_df_parse_sas_raw, 5},
    {"_haven_df_parse_xpt_file", (DL_FUNC) &_haven_df_parse_xpt_file, 1},
    {"_haven_df_parse_xpt_raw", (DL_FUNC) &_haven_df_parse_xpt_raw, 1},
    {"_haven_df_parse_dta_file", (DL_FUNC) &_haven_df_parse_dta_file, 2},
    {"_haven_df_parse_dta_raw", (DL_FUNC) &_haven_df_parse_dta_raw, 2},
    {"_haven_df_parse_sav_file", (DL_FUNC) &_haven_df_parse_sav_file, 3},
    {"_haven_df_parse_sav_raw", (DL_FUNC) &_haven_df_parse_sav_raw, 3},
    {"_haven_df_parse_por_file", (DL_FUNC) &_haven_df_parse_por_file, 3},
    {"_haven_df_parse_por_raw", (DL_FUNC) &_haven_df_parse_por_raw, 3},
    {"_haven_write_sav_", (DL_FUNC) &_haven_write_sav_, 3},
    {"_haven_write_dta_", (DL_FUNC) &_haven_write_dta_, 3},
    {"_haven_write_sas_", (DL_FUNC) &_haven_write_sas_, 2},
    {"_haven_write_xpt_", (DL_FUNC) &_haven_write_xpt_, 4},
    {"is_tagged_na_",            (DL_FUNC) &is_tagged_na_,            2},
    {"na_tag_",                  (DL_FUNC) &na_tag_,                  1},
    {"tagged_na_",               (DL_FUNC) &tagged_na_,               1},
    {NULL, NULL, 0}
};

RcppExport void R_init_haven(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
