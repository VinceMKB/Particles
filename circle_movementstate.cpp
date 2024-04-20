#include "circle_movementstate.h"

CircleMState initCircleMState(float screenWidth, float screenHeight)
{
    CircleMState state;
    state.center = { screenWidth/2, screenHeight/2};
    state.radius = 175.0f;
    state.angle = 0.0f;
    state.speed = 0.01f;
    return state;
}

void updateCircleMState(CircleMState& state)
{
    state.angle += state.speed;
}

Vector2 getCurrentCirclePoint(const CircleMState& state)
{
    float x = state.center.x + state.radius * cosf(state.angle);
    float y = state.center.y + state.radius * sinf(state.angle);

    return {x, y};
}