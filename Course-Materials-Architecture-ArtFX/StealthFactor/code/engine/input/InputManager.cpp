#include "engine/input/InputManager.hpp"

#include <iterator>

namespace engine
{
	namespace input
	{
		Manager::Manager( engine::graphics::Window& _window )
			: window( _window )
		{}

		void Manager::init()
		{
			window.OnFocus.listen( "input::Manager",
				[&]( bool has_focus ) {
				hasFocus = has_focus;
				printf( "Has Focus %d\n", has_focus );
			}
			);
			hasFocus = window.hasFocus();
		
			window.OnKeyPressed.listen( "input::Manager",
				std::bind( &Manager::onKeyPressed, this, std::placeholders::_1 ) 
			);
			window.OnKeyReleased.listen( "input::Manager",
				std::bind( &Manager::onKeyReleased, this, std::placeholders::_1 )
			);
		}

		void Manager::clear()
		{
			justPressedKeys.clear();
			justReleasedKeys.clear();
		}

		bool Manager::isKeyPressed( sf::Keyboard::Key key ) const
		{
			if ( !hasFocus ) return false;
			return sf::Keyboard::isKeyPressed( key );
		}

		bool Manager::isKeyJustPressed( sf::Keyboard::Key key ) const
		{
			if ( !hasFocus ) return false;
			return justPressedKeys.find( key ) != std::end( justPressedKeys );
		}

		bool Manager::isKeyJustReleased( sf::Keyboard::Key key ) const
		{
			if ( !hasFocus ) return false;
			return justReleasedKeys.find( key ) != std::end( justReleasedKeys );
		}

		void Manager::onKeyPressed( const sf::Event::KeyEvent& event )
		{
			justPressedKeys.insert( event.code );
		}

		void Manager::onKeyReleased( const sf::Event::KeyEvent& event )
		{
			justReleasedKeys.insert( event.code );
		}
	}
}
