#ifndef CIRCLE_MOVEMENTSTATE_H
#define CIRCLE_MOVEMENTSTATE_H

#include <stdlib.h>
#include "particles.h"

using namespace std;

struct CircleMState
{
    Vector2 center;
    float radius;
    float angle;
    float speed;
};

CircleMState initCircleMState(float screenWidth, float screenHeight);
void updateCircleMState(CircleMState& state);
Vector2 getCurrentCirclePoint(const CircleMState& state);

#endif