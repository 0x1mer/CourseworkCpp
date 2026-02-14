#include "ConsoleTableRenderer.h"
#include <iostream>
#include <iomanip>

namespace coursework::app
{
	ConsoleTableRenderer::ConsoleTableRenderer(const core::TrainSchedule& schedule)
		: m_schedule(schedule)
	{
	}

	void ConsoleTableRenderer::Render()
	{
        std::cout << "\n=========================================\n";
        std::cout << std::left
            << std::setw(15) << "Destination"
            << std::setw(10) << "Platform"
            << std::setw(10) << "Time"
            << "\n";
        std::cout << "-----------------------------------------\n";

        for (size_t i = 0; i < m_schedule.GetTrainCount(); ++i)
        {
            const auto* train = m_schedule.GetTrain(i);
            if (!train) continue;

            std::cout
                << std::left << std::setw(15) << train->GetDestination()
                << std::setw(10) << train->GetPlatform()
                << std::setw(2) << std::setfill('0') << train->GetHour()
                << ":"
                << std::setw(2) << std::setfill('0') << train->GetMinute()
                << "\n";
        }

        std::cout << "=========================================\n";
	}
} // namespace coursework::app