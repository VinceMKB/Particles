#ifndef POINTS_ON_SCREEN_H
#define POINTS_ON_SCREEN_H

#include <stdlib.h>
#include "particles.h"
#include "square_movementstate.h"
#include "circle_movementstate.h"

using namespace std;



class points_on_screen
{
    
    private:
        Particle *particles;
        SquareMState squareState;
        CircleMState circleState;

    public:

        float screen_Width = 800;
        float screen_Height = 800;
        const int particleCount = 100000;

        points_on_screen();
        ~points_on_screen();
                
        void particle_init();
        void physics(deque <Vector2> points, deque <float> attract_num);

        Vector2 circle_points();
        Vector2 square_points();

        void particles_Draw();
        void circle_Draw();
        void square_Draw();

        void presetOne();
        void presetTwo();
        void presetThree();
        void presetFour();
        
    
};

#endif 