#ifndef ASSIGNMENT_MENU_SCENE
#define ASSIGNMENT_MENU_SCENE

#include "Scene.h"
#include "Button.h"

class AssignmentMenu : public Scene
{
	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif