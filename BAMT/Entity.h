#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include "Component.h"
#include "Debug.h"

#include <vector>

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
	components.push_back(new T);
	Debug::Log("Component Added to Entity!");
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