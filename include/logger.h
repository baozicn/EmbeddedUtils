#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} log_level_t;

void logger_set_level(log_level_t level);
void logger_log(log_level_t level, const char *fmt, ...);

#define LOG_DEBUG(...) logger_log(LOG_LEVEL_DEBUG, __VA_ARGS__)
#define LOG_INFO(...)  logger_log(LOG_LEVEL_INFO,  __VA_ARGS__)
#define LOG_WARN(...)  logger_log(LOG_LEVEL_WARN,  __VA_ARGS__)
#define LOG_ERROR(...) logger_log(LOG_LEVEL_ERROR, __VA_ARGS__)

#endif // LOGGER_H
