#pragma once

#include "ÑoreExport.h"
#include "TimeDefinitions.h"

namespace coursework::core
{
	// Represents a time of day with hour, minute, and second components.
	class CORE_API DepartureTime
	{
		public:
			// Default constructor initializes time to 00:00:00.
			DepartureTime();
			virtual ~DepartureTime() = default;

			// Constructs a Time object with hour, minute, and second.
			// @param hour   Hour value (0-23).
			// @param minute Minute value (0-59).
			// @param second Second value (0-59).
			DepartureTime(types::Hour hour, types::Minute minute, types::Second second);

			// Copy
			DepartureTime(const DepartureTime&) = default;
			DepartureTime& operator=(const DepartureTime&) = default;

			// Move
			DepartureTime(DepartureTime&&) noexcept = default;
			DepartureTime& operator=(DepartureTime&&) noexcept = default;

			// Getters for hour, minute, and second components.
			types::Hour GetHour() const;
			types::Minute GetMinute() const;
			types::Second GetSecond() const;

			// Setters for hour, minute, and second components.
			void SetHour(types::Hour hour);
			void SetMinute(types::Minute minute);
			void SetSecond(types::Second second);

			// Returns total seconds since 00:00:00.
			types::Second GetTotalSeconds() const;

			// Sets the full time.
			// @param hour   Hour (0-23).
			// @param minute Minute (0-59).
			// @param second Second (0-59).
			virtual void SetTime(types::Hour hour, types::Minute minute, types::Second second);
			
			// Arithmetic operators 
			DepartureTime operator+(DepartureTime const& other) const;
			DepartureTime operator-(DepartureTime const& other) const;
			DepartureTime operator+(int seconds) const;
			DepartureTime operator-(int seconds) const;

		private:
			types::Hour m_hour;
			types::Minute m_minute;
			types::Second m_second;

			static DepartureTime FromTotalSeconds(types::Second totalSeconds);
	};

} // namespace coursework::core