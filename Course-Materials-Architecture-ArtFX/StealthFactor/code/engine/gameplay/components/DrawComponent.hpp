#pragma once

#include <engine/gameplay/Component.hpp>
#include <engine/graphics/ShapeList.hpp>

namespace engine
{
	namespace graphics
	{
		class Manager;
	}

	namespace gameplay
	{
		namespace components
		{
			class DrawComponent : public Component
			{
			protected:
            	graphics::ShapeList shapeList;
            	graphics::Manager& graphicsManager;
            		
			public:
				DrawComponent( Entity& _owner, graphics::Manager& _graphics_manager, std::string shape_name );

				virtual void setup();
				virtual void unsetup();
				virtual void draw();
			};
		}
	}
}