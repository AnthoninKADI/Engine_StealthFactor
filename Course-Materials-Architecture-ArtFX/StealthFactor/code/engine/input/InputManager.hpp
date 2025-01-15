#pragma once

#include <set>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "engine/graphics/Window.hpp"

namespace engine
{
	class Engine;

	namespace input
	{
		class Manager
		{
		public:
			Manager(engine::graphics::Window& _window);

			void init();
			void clear();

			bool isKeyPressed(sf::Keyboard::Key key) const;

			bool isKeyJustPressed(sf::Keyboard::Key key) const;

			bool isKeyJustReleased(sf::Keyboard::Key key) const;

			void onKeyPressed(const sf::Event::KeyEvent &event);
			void onKeyReleased(const sf::Event::KeyEvent &event);

		private:
			std::set<sf::Keyboard::Key> justPressedKeys;
			std::set<sf::Keyboard::Key> justReleasedKeys;

			engine::graphics::Window& window;

			bool hasFocus { false };
		};
	}
}
