#pragma once

#include <set>
#include <engine/gameplay/Component.hpp>
#include <ode/collision.h>

namespace engine
{
	namespace physics
	{
		class Manager;
	}

	namespace gameplay
	{
		namespace components
		{
			class PhysicComponent : public Component
			{
			public:
				PhysicComponent( Entity& _owner, physics::Manager& _physics_manager, float box_size_x, float box_size_y );

				virtual void setup();
				virtual void unsetup();

				virtual void updatePhysics();
				std::set<Component*> getCollisions();

			protected:
				dGeomID collisionGeomId;
				physics::Manager& physicsManager;
			};
		}
	}
}

