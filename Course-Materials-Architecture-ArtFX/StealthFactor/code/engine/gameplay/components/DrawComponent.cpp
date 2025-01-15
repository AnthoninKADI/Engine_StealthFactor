#include "DrawComponent.hpp"

#include <engine/gameplay/Entity.hpp>
#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace components
		{
			DrawComponent::DrawComponent( Entity& _owner, graphics::Manager& _graphics_manager, std::string shape_name)
				: graphicsManager( _graphics_manager ), 
				  Component( _owner )
			{
				shapeList.load(shape_name);
			}

			void DrawComponent::setup()
			{
				auto ptr = get_shared_pointer<DrawComponent>();
				graphicsManager.registerComponent( ptr );
			}

			void DrawComponent::unsetup()
			{
				auto ptr = get_shared_pointer<DrawComponent>();
				graphicsManager.unregisterComponent( ptr );
			}

			void DrawComponent::draw()
			{
				graphicsManager.drawShape( shapeList, owner.getTransform() );
			}
		}
	}
}
