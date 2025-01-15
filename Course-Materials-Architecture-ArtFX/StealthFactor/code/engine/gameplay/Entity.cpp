#include "Entity.hpp"

namespace engine
{
	namespace gameplay
	{
		Entity::Entity( engine::Engine& engine )
			: engine( engine ) 
		{}

		Entity::~Entity()
		{
			for ( auto& component : components )
			{
				component->unsetup();
			}
			components.clear();
		}

		const sf::Vector2f & Entity::getPosition() const
		{
			return _position;
		}

		void Entity::setPosition(const sf::Vector2f &newPosition)
		{
			_position = newPosition;
			updateTransform();
		}

		float Entity::getRotation() const
		{
			return _rotation;
		}

		void Entity::setRotation(float newRotation)
		{
			_rotation = newRotation;
			updateTransform();
		}

		const sf::Transform & Entity::getTransform() const
		{
			return _transform;
		}

		void Entity::updateTransform()
		{
			_transform = sf::Transform::Identity;
			_transform.translate(_position);
			_transform.rotate(_rotation);
		}
	}
}