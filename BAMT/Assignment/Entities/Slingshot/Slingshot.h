#ifndef ASSIGNMENT_SLINGSHOT
#define ASSIGNMENT_SLINGSHOT

#include "../../../Core/ECS/Scene.h"
#include "../../../Core/ECS/Entity.h"
#include "../Player.h"
#include "../../../Core/Components/RectRenderer.h"
#include "../../../Core/Components/LineRenderer.h"
#include "../../../Core/Misc/Input.h"

class LineRenderer;

class Slingshot : public Entity
{
	///<summary>
	///	How Far are the poles from the center of this object?
	///</summary>
	float poleDistance = 2.0f;

	float poleWidth = .25f;
	float poleHeight = 3.0f;

	Entity* leftPole = nullptr;
	Entity* rightPole = nullptr;
	Player* box = nullptr;

	LineRenderer* leftLine = nullptr;
	LineRenderer* rightLine = nullptr;

	// Where is the mouse when the player started holding down the drag button?
	Vector2 mouseDragBegin { 0,0};

	bool debugMode = true;



	public:
		void Start() override;
		void Update(float* timeStep) override;
};
#endif