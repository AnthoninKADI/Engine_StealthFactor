#pragma once

namespace engine 
{
	namespace util
	{
		template <typename T>
		class ComponentManager 
		{
		public:
			void registerComponent( std::shared_ptr<T> component )
			{
				components.push_back( component );
			}

			void unregisterComponent( std::shared_ptr<T> component )
			{
				auto itr = std::find( components.begin(), components.end(), component );
				components.erase( itr );
			}

		protected:
			std::vector<std::shared_ptr<T>> components;
		};
	}
}