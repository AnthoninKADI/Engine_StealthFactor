#include "Window.hpp"

namespace engine
{
	namespace graphics
	{
	
	    void Window::pollEvents()
    		{
    			sf::Event event;
    			while (window.pollEvent(event))
    			{
    				switch (event.type)
    				{
    				case sf::Event::GainedFocus:
    					OnFocus.invoke(true);
    					break;
    				case sf::Event::LostFocus:
    					OnFocus.invoke(false);
    					break;
    				case sf::Event::Closed:
    					OnWindowClose.invoke();
    					break;
    				case sf::Event::KeyPressed:
    					OnKeyPressed.invoke(event.key);
    					break;
    				case sf::Event::KeyReleased:
    					OnKeyReleased.invoke(event.key);
    					break;
    				}
    			}
    		}
		
		Window::Window(sf::Int16 width, sf::Int16 height, std::string name)
		{
			window.create(
				sf::VideoMode{
					(unsigned int)width,
					(unsigned int)height
				},
				name
			);
			window.setVerticalSyncEnabled(true);

			sf::View view(
				sf::Vector2f{ 0.f, 0.f },
				sf::Vector2f{ (float)width, (float)height }
			);
			window.setView(view);
		}

		void Window::display()
		{
			window.display();
		}

		void Window::clear()
		{
			window.clear(sf::Color::Black);
		}

		void Window::setView(sf::View view)
		{
			window.setView(view);
		}

		void Window::draw(const sf::Drawable& shape, sf::RenderStates& render_states)
		{
			window.draw(shape, render_states);
		}

		bool Window::hasFocus() const
		{
			return window.hasFocus();
		}

		void Window::close()
		{
			window.close();
		}
	}
}