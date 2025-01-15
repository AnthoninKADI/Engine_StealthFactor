#pragma once

#include "engine/util/Event.hpp"
#include "engine/gameplay/components/DrawComponent.hpp"
#include "Window.hpp"

#include "engine/util/ComponentManager.hpp"

namespace engine
{
	class Engine;

	namespace graphics
	{
		class ShapeList;
		class Window;

		class Manager : public util::ComponentManager<engine::gameplay::components::DrawComponent>
		{
		public:
			Manager( engine::Engine& engine );

			void update();
			void draw();
			void close();

			void setViewPosition( const sf::Vector2f& pos );

			void drawShape(const ShapeList &shapeList, const sf::Transform &transform);

			bool hasFocus() const;

			Window& getWindow() { return window; }

		private:
			void clear();

			Window window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;

			engine::Engine& engine;
		};
	}
}
