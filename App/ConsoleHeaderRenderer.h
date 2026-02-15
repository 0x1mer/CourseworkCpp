#pragma once

namespace coursework::app
{

	// Console renderer that displays a header for the train schedule.
	class ConsoleHeaderRenderer
	{
		public:
			ConsoleHeaderRenderer() = default;

			void Render();
	};

} // namespace coursework::app