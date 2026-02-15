#include "pch.h"
#include "TrainSchedule.h"

#include <stdexcept>

#include "TimeDefinitions.h"

namespace coursework::core
{
	namespace
	{
		// Checks whether a train with similar details exists at approximately the same departure time
		static bool TrainInfoAlreadyExists(
			const std::vector<TrainInfo>& trains,
			const TrainInfo& trainInfo)
		{
			for (const auto& ti : trains)
			{
				if (ti.GetDestination() == trainInfo.GetDestination() &&
					ti.GetPlatform() == trainInfo.GetPlatform() &&
					std::abs(
						static_cast<int>(ti.GetTotalSeconds()) -
						static_cast<int>(trainInfo.GetTotalSeconds())) < 3600)
				{
					return true;
				}
			}
			return false;
		}
	}

	void TrainSchedule::AddTrain(const TrainInfo& train)
	{
		if (TrainInfoAlreadyExists(m_trains, train))
		{
			throw std::invalid_argument("A train with similar details already exists with approximately the same departure time.");
		}
		m_trains.push_back(train);
	}

	const TrainInfo* TrainSchedule::GetTrain(size_t index) const
	{
		if (index >= m_trains.size())
		{
			return nullptr;
		}
		return &m_trains[index];
	}

	size_t TrainSchedule::GetTrainCount() const
	{
		return m_trains.size();
	}

	TrainIterator TrainSchedule::begin()
	{
		return TrainIterator(m_trains.data());
	}

	TrainIterator TrainSchedule::end()
	{
		return TrainIterator(m_trains.data() + m_trains.size());
	}

	const TrainInfo* TrainSchedule::FindNearestTrain(const DepartureTime& time, std::string destination) const
	{
		const TrainInfo* nearestTrain = nullptr;
		std::uint32_t minTimeDiff = constants::time::kSecondsPerDay;

		for (const auto& train : m_trains)
		{
			if (train.GetDestination() == destination)
			{
				std::uint32_t trainTime = train.GetTotalSeconds();
				std::uint32_t currentTime = time.GetTotalSeconds();
				std::uint32_t timeDiff = (trainTime >= currentTime) 
					? (trainTime - currentTime) 
					: (currentTime - trainTime);

				if (timeDiff < minTimeDiff)
				{
					minTimeDiff = timeDiff;
					nearestTrain = &train;
				}
			}
		}
		return nearestTrain;
	}
} // namespace coursework::core