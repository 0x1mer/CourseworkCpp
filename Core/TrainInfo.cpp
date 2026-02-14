#include "pch.h"
#include "TrainInfo.h"
#include <stdexcept>

namespace coursework::core
{
    TrainInfo::TrainInfo() : DepartureTime(0, 0, 0), m_destination("Unknown"), m_platform(0)
    {
    }

    TrainInfo::TrainInfo(
        const std::string& destination,
        std::uint32_t hour,
        std::uint32_t minute,
        std::uint32_t second,
        std::uint32_t platform)
        : DepartureTime(hour, minute, second), m_destination(destination), m_platform(platform)
    {
        if (destination.empty())
        {
            throw std::invalid_argument("Destination cannot be empty");
        }
	}

    TrainInfo::TrainInfo(TrainInfo const& other) noexcept
        : DepartureTime(other), m_destination(other.m_destination), m_platform(other.m_platform)
    {
	}

    std::string TrainInfo::GetDestination() const
    {
        return m_destination;
    }

    std::uint32_t TrainInfo::GetPlatform() const
    {
        return m_platform;
    }

    void TrainInfo::SetDestination(const std::string& destination)
    {
        if (destination.empty())
        {
            throw std::invalid_argument("Destination cannot be empty");
        }
        m_destination = destination;
    }

    void TrainInfo::SetPlatform(std::uint32_t platform)
    {
        m_platform = platform;
    }

    void TrainInfo::SetTime(std::uint32_t hour, std::uint32_t minute, std::uint32_t second)
    {
		SetHour(hour);
		SetMinute(minute);
		SetSecond(second);
	}
} // namespace coursework::core 