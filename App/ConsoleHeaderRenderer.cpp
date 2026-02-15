#include "ConsoleHeaderRenderer.h"
#include <iostream>

namespace coursework::app
{

	void ConsoleHeaderRenderer::Render()
	{
		std::cout << R"(

___________             .__         _________      .__               .___    .__
\__    ___/___________  |__| ____  /   _____/ ____ |  |__   ____   __| _/_ __|  |   ____
  |    |  \_  __ \__  \ |  |/    \ \_____  \_/ ___\|  |  \_/ __ \ / __ |  |  \  | _/ __ \
  |    |   |  | \// __ \|  |   |  \/        \  \___|   Y  \  ___// /_/ |  |  /  |_\  ___/
  |____|   |__|  (____  /__|___|  /_______  /\___  >___|  /\___  >____ |____/|____/\___  >
                      \/        \/        \/     \/     \/     \/     \/               \/

)";
	}

} // namespace coursework::app