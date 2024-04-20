#ifndef SQUARE_MOVEMENTSTATE_H
#define SQUARE_MOVEMENTSTATE_H

#include <stdlib.h>
#include "particles.h"

using namespace std;

struct SquareMState
{
    Vector2 point;
    Vector2 direction;
    Rectangle square;
    enum State{ TL_TR, TR_BR, BR_BL, BL_TL} state;
};

SquareMState initSquareMState();
void updateSquareMState(SquareMState& state);
Vector2 getCurrentPoint(const SquareMState& state);

#endif
