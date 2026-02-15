#pragma once

#include <string>

#include "DepartureTime.h"
#include "ÑoreExport.h"

namespace coursework::core
{
	/// Represents information about a train.
	class CORE_API TrainInfo : public DepartureTime
	{
		public:
			/// Default constructor initializes with default time and platform and "Unknown" destination.
			TrainInfo();

			/// Constructs TrainInfo with full data.
			/// @param destination Train destination.
			/// @param hour Departure hour.
			/// @param minute Departure minute.
			/// @param second Departure second.
			/// @param platform Platform number.
			TrainInfo(
				const std::string& destination,
				std::uint32_t      hour,
				std::uint32_t      minute,
				std::uint32_t      second,
				std::uint32_t      platform);

			/// Copy constructor (noexcept).
			/// @param other TrainInfo instance to copy.
			TrainInfo(TrainInfo const& other) noexcept;

			/// Destructor with default implementation.
			~TrainInfo() = default;

			/// Returns the train destination.
			std::string GetDestination() const;

			/// Returns the platform number.
			std::uint32_t GetPlatform() const;

			/// Sets the train destination.
			/// @param destination New destination string.
			void SetDestination(const std::string& destination);

			/// Sets the platform number.
			/// @param platform New platform number.
			void SetPlatform(std::uint32_t platform);

			/// Sets the departure time.
			/// Overrides the base Time::SetTime method.
			/// @param hour Departure hour (0-23).
			/// @param minute Departure minute (0-59).
			/// @param second Departure second (0-59).
			void SetTime(
				std::uint32_t hour,
				std::uint32_t minute,
				std::uint32_t second) override;

		private:
			std::string   m_destination;
			std::uint32_t m_platform; 
	};
} // namespace coursework::core