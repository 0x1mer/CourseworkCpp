#include "ConsoleMenu.h"
#include <iostream>
#include "ConsoleTableRenderer.h"

namespace coursework::app
{
	void ConsoleMenu::Show(core::TrainSchedule& schedule)
	{
		while (true)
		{
			PrintMenu();
			int choice{};
			std::cin >> choice;
			switch (choice)
			{
				case 1:
					AddTrain(schedule);
					break;
				case 2:
				{
					ConsoleTableRenderer renderer(schedule);
					renderer.Render();
					break;
				}
				case 3:
					return;
				default:
					std::cout << "Invalid choice. Please try again.\n";
			}
		}
	}

	void ConsoleMenu::PrintMenu()
	{
		std::cout << "\nTrain Schedule Management\n";
		std::cout << "1. Add Train\n";
		std::cout << "2. View Schedule\n";
		std::cout << "3. Exit\n";
		std::cout << "Enter your choice: ";
	}

	void ConsoleMenu::AddTrain(core::TrainSchedule& schedule)
	{
		std::string destination;
		std::uint32_t hour, minute, second, platform;

		std::cout << "Enter destination: ";
		std::cin >> destination;
		std::cout << "Enter departure time (hour minute second): ";
		std::cin >> hour >> minute >> second;
		std::cout << "Enter platform number: ";
		std::cin >> platform;

		try
		{
			core::TrainInfo train(destination, hour, minute, second, platform);
			schedule.AddTrain(train);

			std::cout << "Train added successfully.\n";
		}
		catch (const std::exception& ex)
		{
			std::cout << "Error adding train: " << ex.what() << "\n";
		}
	}
} // namespace coursework::app