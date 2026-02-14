#include <iostream>
#include <TrainSchedule.h>
#include "ConsoleMenu.h"
#include "ConsoleHeaderRenderer.h"

int main()
{
	coursework::core::TrainSchedule schedule;

	coursework::app::ConsoleHeaderRenderer header;
	header.Render();

	coursework::app::ConsoleMenu::Show(schedule);
}