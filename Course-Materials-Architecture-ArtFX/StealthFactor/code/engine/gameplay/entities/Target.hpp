#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Target : public Entity
			{
			public:
				Target(engine::Engine& engine);

				virtual void update() override {};
				
			//private:
            //    graphics::ShapeList shapeList;
            //  	dGeomID collisionGeomId;
			};
		}
	}
}
