#pragma once

#include <cstdint>

namespace coursework::types
{

	// Type aliases for time components.
	using Hour = std::uint32_t;
	using Minute = std::uint32_t;
	using Second = std::uint32_t;

} // namespace coursework::types

namespace coursework::constants::time
{

    inline constexpr std::uint32_t kMinValue = 0;
    inline constexpr std::uint32_t kMaxHourValue = 23;
    inline constexpr std::uint32_t kMaxMinuteValue = 59;
    inline constexpr std::uint32_t kMaxSecondValue = 59;
    inline constexpr std::uint32_t kSecondsPerDay = 24u * 60u * 60u;

} // namespace coursework::constants::time