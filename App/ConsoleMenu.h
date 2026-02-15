#pragma once
#include "TrainSchedule.h"

namespace coursework::app
{
	// ConsoleMenu class provides a simple text-based interface for managing the train schedule.
	class ConsoleMenu
	{
		public:
			// Displays the menu and handles user input to manage the train schedule.
			static void Show(core::TrainSchedule& schedule);

		private:
			static void PrintMenu();
			static void AddTrain(core::TrainSchedule& schedule);
	};
} // namespace coursework::app