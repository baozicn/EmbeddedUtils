#include "logger.h"
#include <stdarg.h>

static log_level_t current_level = LOG_LEVEL_DEBUG;

void logger_set_level(log_level_t level) {
    current_level = level;
}

void logger_log(log_level_t level, const char *fmt, ...) {
    if (level < current_level) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    switch(level) {
        case LOG_LEVEL_DEBUG: printf("[DEBUG] "); break;
        case LOG_LEVEL_INFO:  printf("[INFO ] "); break;
        case LOG_LEVEL_WARN:  printf("[WARN ] "); break;
        case LOG_LEVEL_ERROR: printf("[ERROR] "); break;
        default: break;
    }
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}
