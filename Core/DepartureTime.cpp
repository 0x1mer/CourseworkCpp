#include "pch.h"
#include "DepartureTime.h"

#include <stdexcept>

#include "TimeDefinitions.h"

namespace coursework::core
{
    DepartureTime::DepartureTime() : m_hour(0), m_minute(0), m_second(0)
    {
	}

    DepartureTime::DepartureTime(types::Hour hour, types::Minute minute, types::Second second)
        : m_hour(hour), m_minute(minute), m_second(second)
    {
        if (hour > constants::time::kMaxHourValue)
        {
            throw std::out_of_range("Hour out of range");
        }
        if (minute > constants::time::kMaxMinuteValue)
        {
            throw std::out_of_range("Minute out of range");
        }
        if (second > constants::time::kMaxSecondValue)
        {
            throw std::out_of_range("Second out of range");
		}
    }

    types::Hour DepartureTime::GetHour() const
    {
        return m_hour;
    }

    types::Minute DepartureTime::GetMinute() const
    {
        return m_minute;
    }

    types::Second DepartureTime::GetSecond() const
    {
        return m_second;
    }

    types::Second DepartureTime::GetTotalSeconds() const
    {
        return m_hour * 3600 + m_minute * 60 + m_second;
    }

    void DepartureTime::SetHour(types::Hour hour)
    {
        if (hour > constants::time::kMaxHourValue)
        {
            throw std::out_of_range("Hour out of range");
        }
        m_hour = hour;
    }

    void DepartureTime::SetMinute(types::Minute minute)
    {
        if (minute > constants::time::kMaxMinuteValue)
        {
            throw std::out_of_range("Minute out of range");
        }
        m_minute = minute;
    }

    void DepartureTime::SetSecond(types::Second second)
    {
        if (second > constants::time::kMaxSecondValue)
        {
            throw std::out_of_range("Second out of range");
        }
        m_second = second;
    }

    void DepartureTime::SetTime(types::Hour hour, types::Minute minute, types::Second second)
    {
        SetHour(hour);
        SetMinute(minute);
        SetSecond(second);
    }

    DepartureTime DepartureTime::operator+(DepartureTime const& other) const
    {
        return FromTotalSeconds(GetTotalSeconds() + other.GetTotalSeconds());
    }

    DepartureTime DepartureTime::operator-(DepartureTime const& other) const
    {
        std::int32_t diff = static_cast<std::int32_t>(GetTotalSeconds()) -
            static_cast<std::int32_t>(other.GetTotalSeconds());

        if (diff < 0)
        {
            diff += constants::time::kSecondsPerDay;
        }
        return FromTotalSeconds(static_cast<std::uint32_t>(diff));
    }

    DepartureTime DepartureTime::operator+(int seconds) const
    {
        std::int32_t total = static_cast<std::int32_t>(GetTotalSeconds()) + seconds;
        total %= static_cast<int>(constants::time::kSecondsPerDay);

        if (total < 0)
        {
            total += constants::time::kSecondsPerDay;
        }
        return FromTotalSeconds(static_cast<std::uint32_t>(total));
    }

    DepartureTime DepartureTime::operator-(int seconds) const
    {
        return *this + (-seconds);
    }

    DepartureTime DepartureTime::FromTotalSeconds(types::Second totalSeconds)
    {
        totalSeconds %= constants::time::kSecondsPerDay;

        std::uint32_t hour = totalSeconds / 3600;
        totalSeconds %= 3600;
        std::uint32_t minute = totalSeconds / 60;
        std::uint32_t second = totalSeconds % 60;

        return DepartureTime(hour, minute, second);
    }
} // namespace coursework::core