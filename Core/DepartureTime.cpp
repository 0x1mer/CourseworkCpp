#include "pch.h"
#include "DepartureTime.h"

#include <stdexcept>

#include "TimeDefinitions.h"

namespace coursework::core
{
    DepartureTime::DepartureTime() : m_hour(0), m_minute(0), m_second(0)
    {
	}

    DepartureTime::DepartureTime(std::uint32_t hour, std::uint32_t minute, std::uint32_t second)
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

    DepartureTime::DepartureTime(DepartureTime const& other) noexcept
        : m_hour(other.m_hour), m_minute(other.m_minute), m_second(other.m_second)
    {
    }

    std::uint32_t DepartureTime::GetHour() const
    {
        return m_hour;
    }

    std::uint32_t DepartureTime::GetMinute() const
    {
        return m_minute;
    }

    std::uint32_t DepartureTime::GetSecond() const
    {
        return m_second;
    }

    std::uint32_t DepartureTime::GetTotalSeconds() const
    {
        return m_hour * 3600 + m_minute * 60 + m_second;
    }

    void DepartureTime::SetHour(std::uint32_t hour)
    {
        if (hour > constants::time::kMaxHourValue)
        {
            throw std::out_of_range("Hour out of range");
        }
        m_hour = hour;
    }

    void DepartureTime::SetMinute(std::uint32_t minute)
    {
        if (minute > constants::time::kMaxMinuteValue)
        {
            throw std::out_of_range("Minute out of range");
        }
        m_minute = minute;
    }

    void DepartureTime::SetSecond(std::uint32_t second)
    {
        if (second > constants::time::kMaxSecondValue)
        {
            throw std::out_of_range("Second out of range");
        }
        m_second = second;
    }

    void DepartureTime::SetTime(std::uint32_t hour, std::uint32_t minute, std::uint32_t second)
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

    DepartureTime DepartureTime::FromTotalSeconds(std::uint32_t totalSeconds)
    {
        totalSeconds %= constants::time::kSecondsPerDay;

        std::uint32_t hour = totalSeconds / 3600;
        totalSeconds %= 3600;
        std::uint32_t minute = totalSeconds / 60;
        std::uint32_t second = totalSeconds % 60;

        return DepartureTime(hour, minute, second);
    }
} // namespace coursework::core