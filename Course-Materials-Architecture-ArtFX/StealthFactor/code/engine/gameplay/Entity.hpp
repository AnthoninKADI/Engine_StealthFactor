#pragma once

#include <vector>
#include <type_traits>
#include <memory>

#include <SFML/Graphics/Transform.hpp>
#include "Component.hpp"

namespace engine
{
	class Engine;
}

namespace engine
{
	namespace gameplay
	{
		class Entity
		{
		public:
			Entity( engine::Engine& engine );
			virtual ~Entity();

			virtual void update() = 0;

			template <typename T, typename ...Args>
			std::shared_ptr<T> createComponent( Args&&... args )
			{
				static_assert( std::is_base_of<Component, T>::value, "Provided class is NOT deriving from Component!" );
				std::shared_ptr<T> component = std::make_shared<T>( *this, args... );
				component->setup();
				
				components.push_back( component );
				return component;
			}

			const sf::Vector2f &getPosition() const;
			void setPosition(const sf::Vector2f &newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform &getTransform() const;

		protected:
			engine::Engine& engine;

		private:
			std::vector<std::shared_ptr<Component>> components;

			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;

			void updateTransform();
		};
	}
}