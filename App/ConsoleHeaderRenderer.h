#pragma once
#include "IConsoleRenderer.h"

namespace coursework::app
{
	/// Console renderer that displays a header for the train schedule.
	class ConsoleHeaderRenderer final : public IConsoleRenderer
	{
		public:
			/// Constructs a console header renderer.
			ConsoleHeaderRenderer() = default;

			void Render() override;
	};
} // namespace coursework::app