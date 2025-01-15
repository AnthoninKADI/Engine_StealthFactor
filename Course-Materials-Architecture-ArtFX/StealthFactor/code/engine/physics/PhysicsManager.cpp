#include "PhysicsManager.hpp"

#include <cassert>

#include <ode/odeinit.h>

namespace engine
{
	namespace physics
	{
		Manager::Collision::Collision( dGeomID o1, dGeomID o2 )
			: o1 { o1 }
			, o2 { o2 }
		{
		}

		Manager::Manager()
		{
			dInitODE();

			spaceId = dHashSpaceCreate( 0 );
		}

		Manager::~Manager()
		{
			dSpaceDestroy( spaceId );
			dCloseODE();
		}

		void Manager::update()
		{
			for ( auto& component : components )
			{
				component->updatePhysics();
			}

			frameCollisions.clear();
			dSpaceCollide( spaceId, &frameCollisions, &Manager::nearCallback );
		}

		std::set<Component*> Manager::getCollisionsWith( dGeomID obj_id ) const
		{
			std::set<Component*> collisions;

			for ( auto& collision : frameCollisions )
			{
				dGeomID id;
				if ( collision.o1 == obj_id )
				{
					id = collision.o2;
				}
				else if ( collision.o2 == obj_id )
				{
					id = collision.o1;
				}
				else
				{
					continue;
				}

				auto component = reinterpret_cast<Component*>( dGeomGetData( id ) );
				assert( component != nullptr );

				collisions.insert( component );
			}

			return collisions;
		}

		void Manager::nearCallback( void* data, dGeomID o1, dGeomID o2 )
		{
			auto& frameCollisions = *reinterpret_cast<Collisions*>( data );
			frameCollisions.emplace_back( o1, o2 );
		}
	}
}
