#pragma once

#include <ode/collision.h>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			class PhysicComponent;
		}

		namespace entities
		{
			class Player : public Entity
			{
			public:
				Player(engine::Engine& engine);

				virtual void update() override;

				bool hasJustMoved() const { return justMoved; }

			private:
				bool justMoved{ false };
				std::shared_ptr<components::PhysicComponent> physicsComponent;
			};
		}
	}
}
