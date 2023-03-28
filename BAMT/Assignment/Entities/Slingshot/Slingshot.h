#ifndef ASSIGNMENT_SLINGSHOT
#define ASSIGNMENT_SLINGSHOT

#include "../../../Core/ECS/Entity.h"
#include "../../../Core/Components/Transform.h"

class Slingshot : public Entity
{
	public:

		void Start() override;
		void Update(float* timeStep) const override;
};
#endif