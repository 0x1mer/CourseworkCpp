#include <iostream>
#include <sstream>
#include <limits>

#include "ConsoleColors.h"
#include "ConsoleMenu.h"
#include "ConsoleTableRenderer.h"

#include "TimeDefinitions.h"

namespace {

	// RAII guard for stream coloring: writes the given color on construction
	// and writes reset on destruction to prevent color state leakage.
	struct ScopedColor
	{
		std::ostream& os;

		explicit ScopedColor(std::ostream& os, coursework::colors::color c)
			: os(os)
		{
			os << c;
		}

		~ScopedColor()
		{
			os << coursework::colors::color::reset;
		}

		ScopedColor(const ScopedColor&) = delete;
		ScopedColor& operator=(const ScopedColor&) = delete;
	};

	// Simple aggregate representing validated departure time.
	// All fields are guaranteed to be within valid ranges.
	struct Time
	{
		coursework::types::Hour   hour;
		coursework::types::Minute minute;
		coursework::types::Second second;
	};

	// Reads time in HH:MM:SS format from console.
	// Loops until valid input is provided, validates ranges, returns parsed Time.
	inline Time read_time(const std::string& prompt)
	{
		while (true)
		{
			std::cout << prompt;

			ScopedColor guard(std::cout, coursework::colors::color::gray);

			std::string input;
			std::getline(std::cin, input);

			std::istringstream iss(input);

			int hour{}, minute{}, second{};
			char c1{}, c2{};

			using namespace coursework::constants::time;

			if (iss >> hour >> c1 >> minute >> c2 >> second &&
				c1 == ':' && c2 == ':' &&
				iss.eof() &&
				hour >= static_cast<int>(kMinValue) && hour <= static_cast<int>(kMaxHourValue) &&
				minute >= static_cast<int>(kMinValue) && minute <= static_cast<int>(kMaxMinuteValue) &&
				second >= static_cast<int>(kMinValue) && second <= static_cast<int>(kMaxSecondValue))
			{
				return Time{
					static_cast<coursework::types::Hour>(hour),
					static_cast<coursework::types::Minute>(minute),
					static_cast<coursework::types::Second>(second)
				};
			}

			std::cout << coursework::colors::colorize(
				"Invalid format. Use HH:MM:SS (example 14:35:09)\n",
				coursework::colors::color::red
			);
		}
	}

	// Reads an entire line from console (supports spaces).
	// Returns the raw string without additional validation.
	inline std::string read_line(const std::string& prompt)
	{
		std::cout << prompt;

		ScopedColor guard(std::cout, coursework::colors::color::gray);

		std::string value;
		std::getline(std::cin, value);

		// guard вернёт reset автоматически
		return value;
	}

	// Reads a numeric value of type T within [min, max].
	// Uses string parsing to avoid std::cin fail-state issues.
	template <typename T>
	inline T read_number(const std::string& prompt, T min, T max)
	{
		while (true)
		{
			std::cout << prompt;

			ScopedColor guard(std::cout, coursework::colors::color::gray);

			std::string input;
			std::getline(std::cin, input);

			std::istringstream iss(input);

			long long v{};
			if (iss >> v && iss.eof() &&
				v >= static_cast<long long>(min) &&
				v <= static_cast<long long>(max))
			{
				return static_cast<T>(v);
			}

			std::cout << coursework::colors::colorize(
				"Invalid number. Try again.\n",
				coursework::colors::color::red
			);
		}
	}

} // namespace

namespace coursework::app
{
	void ConsoleMenu::Show(core::TrainSchedule& schedule)
	{
		while (true)
		{
			PrintMenu();
			int choice = read_number<int>("Enter your choice: ", 1, 3);

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
					std::cout << colors::colorize(
						"Invalid choice. Please try again.\n",
						colors::color::red
					);
			}
		}
	}

	void ConsoleMenu::PrintMenu()
	{
		std::cout << "\nTrain Schedule Management\n";

		std::cout << "1. " << colors::colorize(
			"Add Train\n",
			colors::color::gray
		);
		std::cout << "2. " << colors::colorize(
			"View Schedule\n",
			colors::color::gray
		);
		std::cout << "3. " << colors::colorize(
			"Exit\n\n",
			colors::color::gray
		);
	}

	void ConsoleMenu::AddTrain(core::TrainSchedule& schedule)
	{
		std::string destination = read_line("Enter destination: ");
		Time departure = read_time("Enter departure time (HH:MM:SS): ");

		uint32_t platform = read_number<uint32_t>("Enter platform number: ", 1u, 99u);

		try
		{
			core::TrainInfo train(destination, departure.hour, departure.minute, departure.second, platform);
			schedule.AddTrain(train);

			std::cout << coursework::colors::colorize("Train added successfully.\n", coursework::colors::color::green);
		}
		catch (const std::exception& ex)
		{
			std::cout << coursework::colors::colorize(std::string("Error adding train: ") + ex.what() + "\n",
				coursework::colors::color::red);
		}
	}

} // namespace coursework::app