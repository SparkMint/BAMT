#ifndef ASSIGNMENT_OBJECT_POOLER
#define ASSIGNEMNT_OBJECT_POOLER

#include "../../Core/EngineManager.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

class EntityPooler : public Component
{
	std::vector<Entity*> entityPool;
	public:
		void Start() override;
		void Update(float* timeStep) override;


		void AddEntityToPool(Entity* entityToAdd);

		Entity* GetAvaliableObject();
};
#endif
