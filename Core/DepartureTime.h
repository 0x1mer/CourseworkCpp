#pragma once

#include <cstdint>

#include "ÑoreExport.h"

namespace coursework::core
{

	/// Represents a time of day with hour, minute, and second components.
	class CORE_API DepartureTime
	{
		public:
			/// Default constructor initializes time to 00:00:00.
			DepartureTime();

			/// Constructs a Time object with hour, minute, and second.
			/// @param hour Hour value (0-23).
			/// @param minute Minute value (0-59).
			/// @param second Second value (0-59).
			DepartureTime(std::uint32_t hour, std::uint32_t minute, std::uint32_t second);

			/// Copy constructor (noexcept).
			/// @param other Time instance to copy.
			DepartureTime(DepartureTime const& other) noexcept;

			/// Destructor with default implementation.
			~DepartureTime() = default;

			/// Returns the hour.
			std::uint32_t GetHour() const;

			/// Returns the minute.
			std::uint32_t GetMinute() const;

			/// Returns the second.
			std::uint32_t GetSecond() const;

			/// Returns total seconds since 00:00:00.
			std::uint32_t GetTotalSeconds() const;

			/// Sets the hour.
			/// @param hour New hour (0-23).
			void SetHour(std::uint32_t hour);

			/// Sets the minute.
			/// @param minute New minute (0-59).
			void SetMinute(std::uint32_t minute);

			/// Sets the second.
			/// @param second New second (0-59).
			void SetSecond(std::uint32_t second);

			/// Sets the full time.
			/// @param hour Hour (0-23).
			/// @param minute Minute (0-59).
			/// @param second Second (0-59).
			virtual void SetTime(std::uint32_t hour, std::uint32_t minute, std::uint32_t second);
			
			/// Adds another Time.
			/// @param other Time instance to add.
			/// @return New Time instance.
			DepartureTime operator+(DepartureTime const& other) const;
			
			/// Subtracts another Time.
			/// @param other Time instance to subtract.
			/// @return New Time instance.
			DepartureTime operator-(DepartureTime const& other) const;

			/// Copy assignment operator.
			/// /// @param other Time instance to assign from.
			/// @return Reference to this Time.
			DepartureTime& operator=(DepartureTime const& other) noexcept = default;

			/// Adds seconds to Time.
			/// @param seconds Number of seconds to add.
			/// @return New Time instance
			DepartureTime operator+(int seconds) const;

			/// Subtracts seconds from Time.
			/// @param seconds Number of seconds to subtract.
			/// @return New Time instance.
			DepartureTime operator-(int seconds) const;

		private:
			std::uint32_t m_hour;   
			std::uint32_t m_minute; 
			std::uint32_t m_second;

			static DepartureTime FromTotalSeconds(std::uint32_t totalSeconds);
	};

} // namespace coursework::core