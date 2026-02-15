#pragma once

#include "TrainSchedule.h"

namespace coursework::app
{
	/// Console renderer that displays train schedule in a tabular format.
	class ConsoleTableRenderer
	{
		public:
			/// Constructs with train schedule reference to render.
			explicit ConsoleTableRenderer(const core::TrainSchedule& schedule);

			void Render();

		private:
			const core::TrainSchedule& m_schedule;
	};
} // namespace coursework::app