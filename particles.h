#include <stdlib.h>
#include <math.h>
#include <raylib.h>

class Particle
{
    private:
        Vector2 position;
        Vector2 velocity;
        Color color;

        float getDistance(Vector2 position);
        Vector2 getNormal(Vector2 sec_position);

    public:
        Particle(int w_screen, int h_screen);
        Particle(Vector2 postion, Vector2 velocity, Color color);

        void Attract(Vector2 attract_to_position, float multiplier);
        void Friction(float f_amount);
        void Move(int w_screen, int h_screen);
        void Draw();

};