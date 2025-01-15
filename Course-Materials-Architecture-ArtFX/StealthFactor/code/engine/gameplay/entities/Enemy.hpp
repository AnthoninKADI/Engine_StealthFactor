#pragma once

#include <string>

#include <ode/collision.h>
#include <engine/gameplay/Entity.hpp>
#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Enemy : public Entity
			{
			public:
				Enemy( engine::Engine& engine, const std::string& archetypeName );

				virtual void update() override;

			private:
				float visionRadius{ 0 };
				int shootDelay{ 0 };
				int shootDelayCounter{ 0 };

				void loadArchetype(const std::string &archetypeName);
				std::string shapeListName;
			};
		}
	}
}
