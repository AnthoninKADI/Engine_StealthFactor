#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>

#include "engine/util/Event.hpp"

namespace engine
{
	namespace graphics
	{
		class Window
		{
		public:

			util::Event<bool> OnFocus;
			util::Event<const sf::Event::KeyEvent&> OnKeyPressed;
			util::Event<const sf::Event::KeyEvent&> OnKeyReleased;
			util::Event<> OnWindowClose;

			Window(sf::Int16 width, sf::Int16 height, std::string name);

			void pollEvents();
			void display();
			void clear();

			void setView(sf::View view);
			void draw(const sf::Drawable& shape, sf::RenderStates& render_states);

			bool hasFocus() const;
			void close();

		private:
			sf::RenderWindow window;
		};
	}
}

