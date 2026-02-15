#pragma once

#include <ostream>
#include <string>
#include <string_view>

namespace coursework::colors
{
    // ANSI escape codes for console colors
    enum class color
    {
        red,
        green,
        yellow,
        blue,
        gray,
        reset
    };

    // Converts a color enum to its corresponding ANSI escape code string.
    inline constexpr const char* to_string(color c)
    {
        switch (c)
        {
        case color::red:    return "\033[31m";
        case color::green:  return "\033[32m";
        case color::yellow: return "\033[33m";
        case color::blue:   return "\033[34m";
        case color::gray:   return "\033[90m";
        case color::reset:  return "\033[0m";
        default:            return "\033[0m";
        }
    }

    // Stream operator for color enum (acts like a manipulator).
    inline std::ostream& operator<<(std::ostream& os, color c)
    {
        return os << to_string(c);
    }

    // Helper function to colorize a string with the specified color.
    inline std::string colorize(std::string_view text, color c)
    {
        return std::string(to_string(c)) + std::string(text) + to_string(color::reset);
    }

} // namespace coursework::colors