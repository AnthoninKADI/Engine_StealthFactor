#pragma once

#include <memory>

namespace engine
{
	namespace gameplay
	{
		class Entity;

		class Component : public std::enable_shared_from_this<Component>
		{
		public:
			Component( Entity& _owner ) 
				: owner( _owner )
			{}
			virtual ~Component() {}

			virtual void setup() = 0;
			virtual void unsetup() = 0;

			template <typename T>
			std::shared_ptr<T> get_shared_pointer()
			{
				return std::static_pointer_cast<T>( shared_from_this() );
			}

			Entity& getOwner() { return owner; }


		protected:
			Entity& owner;
		};
	}
}