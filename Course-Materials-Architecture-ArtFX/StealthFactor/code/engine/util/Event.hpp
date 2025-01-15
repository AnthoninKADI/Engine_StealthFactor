#pragma once

#include <vector>
#include <functional>
#include <map>
#include <string>

namespace engine
{
	namespace util
	{
		template <typename ...TVarargs>
		class Event
		{
		public:
			using func_signature = std::function<void( TVarargs... )>;

		private:
			std::map<std::string, func_signature> observers;

		public:
			void listen( const std::string& key, func_signature observer )
			{
				observers[key] = observer;
			}

			void unlisten( const std::string& key )
			{
				auto itr = observers.find( key );
				if ( itr == observers.end() ) return;

				observers.erase( itr );  
			}

			void invoke( TVarargs ...args )
			{
				for ( auto pair : observers )
					pair.second( args... );
			}
		};
	}
}