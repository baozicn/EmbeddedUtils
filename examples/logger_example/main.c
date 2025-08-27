#include "logger.h"

int main(void) {
    // Set log level to DEBUG to show all messages
    logger_set_level(LOG_LEVEL_DEBUG);

    LOG_DEBUG("Debug message: system initialized.");
    LOG_INFO("Information message: running main loop.");
    LOG_WARN("Warning message: low battery.");
    LOG_ERROR("Error message: sensor failure.");

    return 0;
}
