
#include "PlayerInput.h"

void PlayerInput::Start()
{
    transform = entity->GetComponent<Transform>();
}

void PlayerInput::Update()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W])
    {
        transform->Translate(0, -movementSpeed);
    }

    if (state[SDL_SCANCODE_A])
    {
        transform->Translate(-movementSpeed, 0);
    }

    if (state[SDL_SCANCODE_S])
    {
        transform->Translate(0, movementSpeed);
    }

    if (state[SDL_SCANCODE_D])
    {
        transform->Translate(movementSpeed, 0);
    }
}

void PlayerInput::LateUpdate()
{
}