#pragma once
#include "IConsoleRenderer.h"
#include "TrainSchedule.h"

namespace coursework::app
{
	/// Console renderer that displays train schedule in a tabular format.
	class ConsoleTableRenderer final : public IConsoleRenderer
	{
		public:
			/// Constructs with train schedule reference to render.
			explicit ConsoleTableRenderer(const core::TrainSchedule& schedule);

			void Render() override;

		private:
			const core::TrainSchedule& m_schedule;
	};
} // namespace coursework::app