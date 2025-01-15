#pragma once

#include <set>
#include <string>
#include <memory>

#include <SFML/System/Vector2.hpp>

namespace engine
{
	class Engine;

	namespace gameplay
	{
		class Entity;

		namespace entities
		{
			class Player;
		}

		class Manager
		{
		public:
			Manager( engine::Engine& engine );
			virtual ~Manager();

			void update();

			void gameOver();

			void loadMap(const std::string& map_name);
			void scheduleLoadMap( const std::string& map_name );
			void scheduleLoadNextMap();

			sf::Vector2f getViewCenter() const;
			std::weak_ptr<entities::Player> getPlayer() const { return playerEntity; }

			static const float CELL_SIZE;

		private:
			std::set<std::shared_ptr<Entity>> entitiesContainer;
			std::weak_ptr<entities::Player> playerEntity;

			std::string currentMapName;
			std::string nextMapName;
			int rows{ 0 };
			int columns{ 0 };

			bool preventMapCompletion{ false };
			bool nextMapRequested{ false };

			engine::Engine& engine;
		};
	}
}
