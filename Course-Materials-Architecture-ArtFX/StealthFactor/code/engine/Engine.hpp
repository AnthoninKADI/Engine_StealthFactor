#pragma once

#include <string>

#include "gameplay/GameplayManager.hpp"
#include "graphics/GraphicsManager.hpp"
#include "physics/PhysicsManager.hpp"
#include "input/InputManager.hpp"
#include "util/Event.hpp"

namespace engine
{
	class Engine
	{
	public:
		Engine();

		void loadConfiguration();

		void run();
		void exit();

		float getDeltaTime() const { return deltaTime; }

		gameplay::Manager& getGameplayManager() { return *gameplayManager; }
		graphics::Manager& getGraphicsManager() { return *graphicsManager; }
		physics::Manager& getPhysicsManager() { return *physicsManager; }
		input::Manager& getInputManager() { return *inputManager; }

	private:
		bool running { false };
		float deltaTime { 0.0f };

		std::unique_ptr<gameplay::Manager> gameplayManager;
		std::unique_ptr<graphics::Manager> graphicsManager;
		std::unique_ptr<physics::Manager> physicsManager;
		std::unique_ptr<input::Manager> inputManager;
		std::string startMap;
	};
}
