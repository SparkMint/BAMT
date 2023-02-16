#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include "Component.h"
#include "Debug.h"

#include <vector>

class Component;

class Entity 
{


	private:
		/// <summary>
		/// The list of components attached to this entity.
		/// </summary>
		std::vector<Component*> components;

	public:
		Entity();

		// Having to put implementation into a header file is annoying, but its
		// the only way for this to work. Fun.
		template<class T>
		void AddComponent();

		template<class T>
		T* GetComponent();
};

template<class T>
inline void Entity::AddComponent()
{
	// Create a new instance of this Type.
	T* c = new T();

	// Try use Dynamic Casting to get the base component.
	Component* componentBase = dynamic_cast<Component*>(c);
	if (componentBase != nullptr)
	{
		componentBase->entity = this;
		components.push_back(componentBase);
		Debug::Log("Component Added to Entity!");
	}
	else
	{
		Debug::Log("Invalid component type!");
		delete(c);
	}

}

template<class T>
inline T* Entity::GetComponent() 
{
	for (Component* c : components)
	{
		if (dynamic_cast<T*>(c))
		{
			Debug::Log("Component Found on Entity.");
			return static_cast<T*>(c);
		}
	}
	Debug::LogError("Component could not be found on this entity.");
	return nullptr;
}
#endif // !BAMT_ENTITY