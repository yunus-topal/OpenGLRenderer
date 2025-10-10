#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace eng {
    inline void init_logger(const char* pattern = "%Y-%m-%d %T.%e [%^%l%$] %v") {
        static bool inited = false;
        if (inited) return;
        auto logger = spdlog::stdout_color_mt("engine");
        logger->set_pattern(pattern);
        logger->set_level(static_cast<spdlog::level::level_enum>(SPDLOG_ACTIVE_LEVEL));
        spdlog::set_default_logger(logger);
        inited = true;
    }
} // namespace eng

// Convenience macros
#define LOG_TRACE(...) ::spdlog::trace(__VA_ARGS__)
#define LOG_INFO(...)  ::spdlog::info(__VA_ARGS__)
#define LOG_WARN(...)  ::spdlog::warn(__VA_ARGS__)
#define LOG_ERR(...)   ::spdlog::error(__VA_ARGS__)