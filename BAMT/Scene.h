#ifndef BAMT_SCENE
#define BAMT_SCENE

#include "Entity.h"
#include <algorithm>

class EngineManager;

class Scene
{
	std::vector<Entity*> _entityList;

	public:
		EngineManager* engine = nullptr;

		// Determines if scene logic should run.
		bool active = false;

		// If set to true, this scene will always run no matter what.
		bool alwaysActive = false;

		virtual void Start();

		/// <summary>
		/// Updates all active Entities.
		/// </summary>
		void Update(float* timeStep) const;

		/// <summary>
		/// Renders all active Entities.
		/// </summary>
		void Render(SDL_Renderer* renderer) const;

		/// ENTITY FACTORY DECLARATION

		/// <summary>
		/// Creates an Entity of the specified type and adds it to the Entity List.
		/// </summary>
		template<class T = Entity, typename... TArgs>
		T* AddEntity(TArgs&&... mArgs);

		/// <summary>
		/// Destroys a specified Entity and removes it from the Entity List.
		/// </summary>
		void RemoveEntity(Entity* ent);

		/// <summary>
		/// Sorts all entities in the scene for rendering purposes.
		/// </summary>
		void SortEntities();

		Scene();
		~Scene();
};

/// ENTITY FACTORY IMPLEMENTATION

template<class T, typename... TArgs>
inline T* Scene::AddEntity(TArgs&&... mArgs)
{
	// Create a new instance of this type and pass its arguments.
	T* ent = new T(std::forward<TArgs>(mArgs)...);

	// Use Dynamic Casting to find if the type given is derived from Entity.
	Entity* entityBase = dynamic_cast<Entity*>(ent);
	if (entityBase != nullptr)
	{
		// Add the entity to our entity list.
		_entityList.emplace_back(entityBase);

		entityBase->scene = this;

		entityBase->Start();
		return ent;
	}

	// If it got here, the type we got wasn't an entity type.
	Debug::LogError("This entity could not be created successfully!", ent);
	delete(ent);
	return nullptr;
}

inline void Scene::RemoveEntity(Entity* ent)
{
	auto entityToRemove = remove(_entityList.begin(), _entityList.end(), ent);
	delete(ent);
}
#endif