#include "Target.hpp"

#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include "engine/gameplay/components/DrawComponent.hpp"
#include "engine/gameplay/components/PhysicComponent.hpp"

#include "engine/Engine.hpp"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target( engine::Engine& engine )
				: Entity( engine )
			{
				createComponent<components::PhysicComponent>(
					engine.getPhysicsManager(),
					gameplay::Manager::CELL_SIZE * 0.9f,
					gameplay::Manager::CELL_SIZE * 0.9f
				);

				createComponent<components::DrawComponent>(
					engine.getGraphicsManager(),
					"target"
				);
			}
		}
	}
}
