#include "PlayerMoveMouse.h"

void PlayerMoveMouse::Start()
{
    transform = entity->GetComponent<Transform>();
}

void PlayerMoveMouse::Update()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    positions.push_back(new Vector2{ x, y });


    if (positions.size() - 1 >= movementdelay)
    {
        transform->SetX(positions[0]->x);
        transform->SetY(positions[0]->y);
    }
    if (positions.size() - 1 > movementdelay)
    {
        delete(positions[0]);
        positions.erase(positions.begin());
    }
}

void PlayerMoveMouse::Render()
{
}
