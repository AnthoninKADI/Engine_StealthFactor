#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/Engine.hpp>
#include "engine/gameplay/components/DrawComponent.hpp"
#include "engine/gameplay/components/PhysicComponent.hpp"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Player::Player( engine::Engine& engine )
				: Entity( engine )
			{
				physicsComponent = createComponent<components::PhysicComponent>(
					engine.getPhysicsManager(),
					gameplay::Manager::CELL_SIZE * 0.9f, 
					gameplay::Manager::CELL_SIZE * 0.9f
				);

				createComponent<components::DrawComponent>(
					engine.getGraphicsManager(),
					"player"
				);
			}

			void Player::update()
			{
				justMoved = false;
				auto position = getPosition();
				float rotation = getRotation();

				auto& input_manager = engine.getInputManager();
				if ( input_manager.isKeyJustPressed( sf::Keyboard::Left ) )
				{
					justMoved = true;
					position.x -= gameplay::Manager::CELL_SIZE;
					rotation = 180.f;
				}
				if ( input_manager.isKeyJustPressed( sf::Keyboard::Right ) )
				{
					justMoved = true;
					position.x += gameplay::Manager::CELL_SIZE;
					rotation = 0.f;
				}
				if ( input_manager.isKeyJustPressed( sf::Keyboard::Up ) )
				{
					justMoved = true;
					position.y -= gameplay::Manager::CELL_SIZE;
					rotation = -90.f;
				}
				if ( input_manager.isKeyJustPressed( sf::Keyboard::Down ) )
				{
					justMoved = true;
					position.y += gameplay::Manager::CELL_SIZE;
					rotation = 90.f;
				}

				if ( justMoved )
				{
					setPosition( position );
					setRotation( rotation );
				}

				auto collisions = physicsComponent->getCollisions();
				for ( auto& component : collisions )
				{
					auto entity = &component->getOwner();
					auto targetEntity = dynamic_cast<entities::Target*>( entity );
					if ( targetEntity )
					{
						engine.getGameplayManager().scheduleLoadNextMap();
					}
				}
			}
		}
	}
}
