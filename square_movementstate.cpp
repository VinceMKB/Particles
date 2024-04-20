#include "square_movementstate.h"

SquareMState initSquareMState()
{
    SquareMState state;
    state.square = {300, 300, 200, 200};
    state.point = {state.square.x, state.square.y};
    state.direction = {1, 0};
    state.state = SquareMState::TL_TR;
    return state;
}

void updateSquareMState(SquareMState& state)
{
    state.point.x += state.direction.x;
    state.point.y += state.direction.y;

    switch (state.state)
    {
        case SquareMState::TL_TR:
            if(state.point.x == state.square.x + state.square.width)
            {
                state.direction = {0, 1};
                state.state = SquareMState::TR_BR;
            }
            break;
        
        case SquareMState::TR_BR:
            if(state.point.y == state.square.y + state.square.height)
            {
                state.direction = {-1, 0};
                state.state = SquareMState::BR_BL;
            }
            break;
        
        case SquareMState::BR_BL:
            if(state.point.x == state.square.x)
            {
                state.direction = {0, -1};
                state.state = SquareMState::BL_TL;
            }
            break;
        
        case SquareMState::BL_TL:
            if(state.point.y == state.square.x)
            {
                state.direction = {1, 0};
                state.state = SquareMState::TL_TR;
            }
            break;
    }
}

Vector2 getCurrentSquarePoint(const SquareMState& state)
{
    return state.point;
}