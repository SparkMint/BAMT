#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include "Component.h"
#include "Debug.h"
#include "SDL.h"

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
		Entity(SDL_Renderer* renderer);

		/// <summary>
		/// If active, components on this entity will call their respective logic.
		/// </summary>
		bool active;

		// Pointer reference to the renderer.
		SDL_Renderer* renderer;

		/// <summary>
		/// Runs all component logic on this entity.
		/// </summary>
		void ComponentsCallUpdate();

		/// <summary>
		/// Runs all component logic on this entity.
		/// </summary>
		void ComponentsCallLateUpdate();

		// Having to put implementation into a header file is annoying, but its
		// the only way for this to work. Fun.
		template<class T, typename... TArgs>
		void AddComponent(TArgs&&... mArgs);

		template<class T>
		T* GetComponent();
};

template<class T, typename... TArgs>
inline void Entity::AddComponent(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* c = (new T(std::forward<TArgs>(mArgs)...));

	// Try use Dynamic Casting to get the base component.
	Component* componentBase = dynamic_cast<Component*>(c);
	if (componentBase != nullptr)
	{
		componentBase->entity = this;
		components.push_back(componentBase);
		Debug::Log("Component Added to Entity!");

		// Run the start function on the newly created component.
		componentBase->Start();
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
			//Debug::Log("Component Found on Entity.");
			return static_cast<T*>(c);
		}
	}
	Debug::LogError("Component could not be found on this entity.");
	return nullptr;
}


#endif // !BAMT_ENTITY