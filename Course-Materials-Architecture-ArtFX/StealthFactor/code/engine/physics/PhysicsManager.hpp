#pragma once

#include <set>
#include <vector>
#include <ode/collision.h>
#include "engine/gameplay/components/PhysicComponent.hpp"

#include "engine/util/ComponentManager.hpp"

using namespace engine::gameplay;

namespace engine
{
	namespace physics
	{
		class Manager : public util::ComponentManager<components::PhysicComponent>
		{
		public:
			struct Collision
			{
				dGeomID o1;
				dGeomID o2;

				Collision( dGeomID o1, dGeomID o2 );
			};

			using Collisions = std::vector<Collision>;

			Manager();
			~Manager();

			void update();

			std::set<Component*> getCollisionsWith( dGeomID obj_id ) const;

			dSpaceID getSpaceId() const { return spaceId; }

		private:
			dSpaceID spaceId;
			Collisions frameCollisions;

			static void nearCallback( void* data, dGeomID o1, dGeomID o2 );
		};
	}
}
