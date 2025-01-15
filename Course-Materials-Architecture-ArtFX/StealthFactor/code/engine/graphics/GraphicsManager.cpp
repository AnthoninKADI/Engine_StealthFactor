#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <engine/input/InputManager.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/Engine.hpp>

namespace engine
{
	namespace graphics
	{
		Manager::Manager( engine::Engine& engine )
			: engine( engine ), window(WINDOW_WIDTH, WINDOW_HEIGHT, "Stealth Factor")
		{
		}

		void Manager::update()
		{
			window.pollEvents();
		}

		void Manager::draw()
		{
			clear();

			for ( auto& component : components )
			{
				component->draw();
			}

			window.display();
		}

		void Manager::close()
		{
			window.close();
		}

		void Manager::setViewPosition( const sf::Vector2f& pos )
		{
			sf::View view {
				pos,
				sf::Vector2f{(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT}
			};
			window.setView( view );
		}

		void Manager::drawShape( const ShapeList& shapeList, const sf::Transform& transform )
		{
			sf::RenderStates renderStates { transform };
			for ( auto shape : shapeList.getShapes() )
			{
				window.draw( *shape, renderStates );
			}
		}

		bool Manager::hasFocus() const
		{
			return window.hasFocus();
		}

		void Manager::clear()
		{
			window.clear();
		}
	}
}
