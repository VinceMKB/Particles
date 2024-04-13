#include <stdlib.h>
#include "particles.h"

using namespace std;



class points_on_screen
{
    
    private:
        Particle *particles;

    public:

        float screen_Width = 800;
        float screen_Height = 800;
        const int particleCount = 100000;

        points_on_screen();
        ~points_on_screen();
                
        void particle_init();
        void physics(deque <Vector2> points);
        Vector2 circle_points();
        void particles_Draw();
        void circle_Draw();
        void presetOne();
        
    
};