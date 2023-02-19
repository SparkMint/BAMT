#include "GameObject.h"

GameObject::GameObject()
{
	AddComponent<Transform>(250, 250);
	AddComponent<TriRenderer>(50);
}
