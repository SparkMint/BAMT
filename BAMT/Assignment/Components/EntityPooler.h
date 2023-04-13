#ifndef ASSIGNMENT_OBJECT_POOLER
#define ASSIGNEMNT_OBJECT_POOLER

#include "../../Core/ECS/Entity.h"
#include "../../Core/ECS/Component.h"

class EntityPooler : public Component
{
	std::vector<Entity*> entityPool;

	public:
		void AddEntityToPool(Entity* entityToAdd);

		Entity* GetAvaliableObject();
		Entity* GetRandomAvaliableObject(int attempts = 5);
};
#endif
