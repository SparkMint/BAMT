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
		~Entity();

		/// <summary>
		/// Pointer to the engine this entity is attached to.
		/// </summary>
		EngineManager* engine = nullptr;


		/// <summary>
		/// What Entity owns this one?
		/// </summary>
		Entity* parent = nullptr;

		/// <summary>
		/// List of entities owned by this Entity.
		/// </summary>
		std::vector<Entity*> children;

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
		virtual void Start();

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

		template<class T>
		void SetParent(T* entity);

		template<class T>
		void AddChild(T* entity);
};

// Implementation for Templates is easiest within the header file.
// Its annoying, but its the only way I can get this to work.

template<class T, typename... TArgs>
T* Entity::AddComponent(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* c = (new T(std::forward<TArgs>(mArgs)...));

	// Try use Dynamic Casting to get the base component.
	Component* componentBase = dynamic_cast<Component*>(c);
	if (componentBase != nullptr)
	{
		componentBase->entity = this;
		_components.push_back(componentBase);
		//Debug::Log("Component Added to Entity!", c);

		// Run the start function on the newly created component.
		componentBase->Start();
		return c;
	}
	else
	{
		Debug::Log("Invalid Component type, this cannot be added onto this Entity!", this);
		delete(c);
		return nullptr;
	}
}

template<class T>
T* Entity::GetComponent() 
{
	for (Component* c : _components)
	{
		if (dynamic_cast<T*>(c))
		{
			//Debug::Log("Component Found on Entity!", c);
			return static_cast<T*>(c);
		}
	}
	Debug::LogError("Component could not be found on this Entity!", this);
	return nullptr;
}


template <class T>
void Entity::SetParent(T* entity)
{
	Entity* entityBase = dynamic_cast<Entity*>(entity);

	// If it isn't null, it's a valid Entity.
	if (entityBase != nullptr && entityBase != this)
	{
		// Check if the entity is already a child of the new parent.
		auto iterator = std::find(entityBase->children.begin(), entityBase->children.end(), this);
		if (iterator == entityBase->children.end())
		{
			// Remove the entity from its current parents children list, if it has one.
			if (parent != nullptr)
			{
				auto childInParent = std::find(parent->children.begin(), parent->children.end(), this);
				if (childInParent != parent->children.end())
					parent->children.erase(childInParent);
			}
			// Set the new parent.
			parent = entityBase;

			// Add the entity to the new parent's children list.
			parent->children.push_back(this);
		}
	}
	else
	{
		Debug::LogError("Entity given was not a type of entity!", entity);
	}
}

// old method. keeping just incase.
/*
template <class T>
void Entity::SetParent(T* entity)
{
	Entity* entityBase = dynamic_cast<Entity*>(entity);

	// If it isnt null, its a valid Entity.
	if (entityBase != nullptr)
	{
		parent = entityBase;

		// Tell the parent it now has a child.
		auto entityInChildren = std::find(entityBase->children.begin(), entityBase->children.end(), this);

		// If we cant find the entity in the parents children list, add it.
		if(entityInChildren == entityBase->children.end())
			entityBase->AddChild(this);
	}
}*/

template <class T>
void Entity::AddChild(T* entity)
{
	Entity* entityBase = dynamic_cast<Entity*>(entity);

	// If it isnt null, its a valid Entity.
	if (entityBase != nullptr)
	{
		// Try find out if this object is already a child of this Entity
		auto iterator = std::find(children.begin(), children.end(), entityBase);

		// If we didnt find the target object in our children list. Add it
		if (iterator == children.end())
		{
			children.push_back(entityBase);

			entityBase->SetParent(this);
		}
	}
}
#endif
