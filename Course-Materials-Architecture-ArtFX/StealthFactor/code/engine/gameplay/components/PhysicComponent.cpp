#include "PhysicComponent.hpp"

#include <engine/gameplay/Entity.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			PhysicComponent::PhysicComponent( Entity& _owner, physics::Manager& _physics_manager, float box_size_x, float box_size_y)
				: physicsManager( _physics_manager ),
				Component( _owner )
			{
				collisionGeomId = dCreateBox(physicsManager.getSpaceId(), box_size_x, box_size_y, 1.0f);
			}

			void PhysicComponent::setup()
			{
				dGeomSetData(collisionGeomId, this);
				auto ptr = get_shared_pointer<PhysicComponent>();
				physicsManager.registerComponent( ptr );
			}

			void PhysicComponent::unsetup()
			{
				dGeomDestroy(collisionGeomId);
				auto ptr = get_shared_pointer<PhysicComponent>();
				physicsManager.unregisterComponent( ptr );
			}

			void PhysicComponent::updatePhysics()
			{
				sf::Vector2f position = owner.getPosition();
				dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
			}

			std::set<Component*> PhysicComponent::getCollisions()
			{
				return physicsManager.getCollisionsWith(collisionGeomId);
			}
		}
	}
}
