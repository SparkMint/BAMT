#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include "Component.h"
#include "Debug.h"
#include "SDL.h"

#include <vector>

class EngineManager;
class Component;

class Entity 
{
	/// <summary>
	/// The list of Components attached to this entity.
	/// </summary>
	std::vector<Component*> _components;

	public:
		Entity();

		/// <summary>
		/// Pointer to the engine this entity is attached to.
		/// </summary>
		EngineManager* engine = nullptr;

		/// <summary>
		/// Should this Entity run any logic?
		/// </summary>
		bool active = true;

		/// <summary>
		/// What layer should this Entity Draw on?
		/// </summary>
		int renderLayer = 0;

		/// <summary>
		/// Used to let the entity perform initialization when created.
		/// </summary>
		virtual void Start() = 0;

		/// <summary>
		/// Runs Update on all Components attached to this Entity.
		/// </summary>
		void Update(float* timeStep) const;

		/// <summary>
		/// Runs Render on all Components attached to this Entity.
		/// </summary>
		void Render(SDL_Renderer* renderer) const;

		/// <summary>
		/// Adds a specified Component to this Entity.
		/// </summary>
		/// <typeparam name="T">- The Component to add.</typeparam>
		template<class T, typename... TArgs>
		T* AddComponent(TArgs&&... mArgs);

		/// <summary>
		/// Tries to get a Component from this Entity.
		/// </summary>
		template<class T>
		T* GetComponent();
};

// Implementation for Templates is easiest within the header file.
// Its annoying, but its the only way I can get this to work.

template<class T, typename... TArgs>
inline T* Entity::AddComponent(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* c = (new T(std::forward<TArgs>(mArgs)...));

	// Try use Dynamic Casting to get the base component.
	Component* componentBase = dynamic_cast<Component*>(c);
	if (componentBase != nullptr)
	{
		componentBase->entity = this;
		_components.push_back(componentBase);
		Debug::Log("Component Added to Entity!");

		// Run the start function on the newly created component.
		componentBase->Start();
		return c;
	}
	else
	{
		Debug::Log("Invalid Component type!");
		delete(c);
		return nullptr;
	}
}

template<class T>
inline T* Entity::GetComponent() 
{
	for (Component* c : _components)
	{
		if (dynamic_cast<T*>(c))
		{
			Debug::Log("Component Found on Entity!");
			return static_cast<T*>(c);
		}
	}
	Debug::LogError("Component could not be found on this Entity!");
	return nullptr;
}
#endif