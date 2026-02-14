#pragma once
#include <string>

namespace coursework::app
{
	/// Interface for rendering text to the console.
	class IConsoleRenderer
	{
		public:
			virtual ~IConsoleRenderer() = default;

			// Renders the given text to the console.
			virtual void Render() = 0;
	};
} // namespace coursework::app