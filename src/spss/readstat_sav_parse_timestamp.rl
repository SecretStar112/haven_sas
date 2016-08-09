
#include <time.h>
#include "../readstat.h"
#include "../readstat_iconv.h"

#include "readstat_sav.h"
#include "readstat_sav_parse_timestamp.h"

%%{
    machine sav_time_parse;
    write data nofinal noerror;
}%%

readstat_error_t sav_parse_time(const char *data, size_t len, struct tm *timestamp, sav_ctx_t *ctx) {
    readstat_error_t retval = READSTAT_OK;
    char error_buf[8192];
    const char *p = data;
    const char *pe = p + len;
    const char *eof = pe;
    int cs;
    int temp_val = 0;
    %%{
        action incr_val {
            temp_val = 10 * temp_val + (fc - '0');
        }

        integer2 = [0-9]{2} >{ temp_val = 0; } $incr_val;

        hour = integer2 %{ timestamp->tm_hour = temp_val; };

        minute = integer2 %{ timestamp->tm_min = temp_val; };

        second = integer2 %{ timestamp->tm_sec = temp_val; };

        main := hour ":" minute ":" second;

        write init;
        write exec;
    }%%

    if (cs < %%{ write first_final; }%%|| p != pe) {
        if (ctx->error_handler) {
            snprintf(error_buf, sizeof(error_buf), "Invalid time string (length=%d): %*s", (int)len, (int)-len, data);
            ctx->error_handler(error_buf, ctx->user_ctx);
        }
        retval = READSTAT_ERROR_BAD_TIMESTAMP;
    }

    (void)sav_time_parse_en_main;

    return retval;
}

%%{
    machine sav_date_parse;
    write data nofinal noerror;
}%%

readstat_error_t sav_parse_date(const char *data, size_t len, struct tm *timestamp, sav_ctx_t *ctx) {
    readstat_error_t retval = READSTAT_OK;
    char error_buf[8192];
    const char *p = data;
    const char *pe = p + len;
    const char *eof = pe;
    int cs;
    int temp_val = 0;
    %%{
        action incr_val {
            temp_val = 10 * temp_val + (fc - '0');
        }

        action save_year {
            if (temp_val < 70) {
                timestamp->tm_year = 100 + temp_val;
            } else {
                timestamp->tm_year = temp_val;
            }
        }

        integer2 = [0-9]{2} >{ temp_val = 0; } $incr_val;

        day = integer2 %{ timestamp->tm_mday = temp_val; };

        year = integer2 %save_year;

        month = 
            "Jan" %{ timestamp->tm_mon = 0; } |
            "Feb" %{ timestamp->tm_mon = 1; } |
            "Mar" %{ timestamp->tm_mon = 2; } |
            "Apr" %{ timestamp->tm_mon = 3; } |
            "May" %{ timestamp->tm_mon = 4; } |
            "Jun" %{ timestamp->tm_mon = 5; } |
            "Jul" %{ timestamp->tm_mon = 6; } |
            "Aug" %{ timestamp->tm_mon = 7; } |
            "Sep" %{ timestamp->tm_mon = 8; } |
            "Oct" %{ timestamp->tm_mon = 9; } |
            "Nov" %{ timestamp->tm_mon = 10; } |
            "Dec" %{ timestamp->tm_mon = 11; };

        main := day " " month " " year;

        write init;
        write exec;
    }%%

    if (cs < %%{ write first_final; }%%|| p != pe) {
        if (ctx->error_handler) {
            snprintf(error_buf, sizeof(error_buf), "Invalid date string (length=%d): %*s", (int)len, (int)-len, data);
            ctx->error_handler(error_buf, ctx->user_ctx);
        }
        retval = READSTAT_ERROR_BAD_TIMESTAMP;
    }

    (void)sav_date_parse_en_main;

    return retval;
}
