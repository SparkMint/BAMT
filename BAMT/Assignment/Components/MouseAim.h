#ifndef ASSIGNMENT_MOUSE_AIM
#define ASSIGNMENT_MOUSE_AIM

#include "../../Core/EngineManager.h"
#include "../../Core/Components/Transform.h"
#include "../../Core/ECS/Component.h"
#include "../../Core/Misc/Input.h"

class MouseAim : public Component
{
	public:
		/// <summary>
		/// Returns the direction the mouse was looking relative to the sourcePosition
		/// </summary>
		/// <param name="sourcePosition">The starting position of the outputted direction vector</param>
		/// <returns>Direction of the mouse relative to the starting position</returns>
		Vector2 GetAimDirection(const Vector2* sourcePosition);
};
#endif