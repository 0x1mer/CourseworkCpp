#pragma once
#include <vector>
#include "TrainInfo.h"
#include "TrainIterator.h"

#ifdef COURSEWORK_CORE_EXPORTS
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

namespace coursework::core
{
	/// Represents a schedule of trains.
	class CORE_API TrainSchedule
	{
		public:
			/// Adds a train to the schedule.
			/// @param train Train information to add.
			void AddTrain(const TrainInfo& train);

			/// Gets train by index.
			/// @param index Zero-based index.
			/// @return Pointer to TrainInfo or nullptr if index is out of range.
			const TrainInfo* GetTrain(size_t index) const;

			/// Returns the total number of trains in the schedule.
			size_t GetTrainCount() const;

			/// Returns iterator to the first train.
			TrainIterator begin();

			/// Returns iterator to one-past-last train.
			TrainIterator end();

			/// Finds the nearest train for given destination and time.
			/// @param time Current time reference.
			/// @param destination Destination to search for.
			/// @return Pointer to nearest TrainInfo or nullptr if none found.
			const TrainInfo* FindNearestTrain(const DepartureTime& time, std::string destination) const;

		private:
			std::vector<TrainInfo> m_trains;
	};
} // namespace coursework::core