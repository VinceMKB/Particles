#include <iostream>
#include <raylib.h>

#include "particles.h"
using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 800;

    Vector2 circleCenter = {screenWidth/2, screenHeight/2};
    float radius = 175.0f;
    float angle = 0.0f;
    float speed = 0.01f;

    Vector2 one_pos = {400, 225};
    Vector2 two_pos = {276.2563133, 523.7436867};
    Vector2 three_pos = {523.7436867, 523.7436867};

    SetRandomSeed(1);

    const int particleCount = 100000;
    Particle *particles = (Particle*)malloc(particleCount * sizeof(Particle));

    for(long int i = 0; i < particleCount; i++)
    {
        particles[i] = Particle(screenWidth, screenHeight);
    }

    InitWindow(screenWidth, screenHeight, "Particles");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        
        Vector2 four_pos = {(float)GetMouseX(), (float)GetMouseY()};
        
        angle += speed;

        float x = circleCenter.x + radius *cosf(angle);
        float y = circleCenter.y + radius *sinf(angle);
        Vector2 five_pos = {x, y};

        for(long int i = 0; i < particleCount; i++)
        {

            particles[i].Attract(one_pos, 2.5);
            particles[i].Attract(two_pos, 2.5);
            particles[i].Attract(three_pos, 2.5);
            particles[i].Attract(four_pos, 1.5);
            particles[i].Attract(five_pos, 5);
            particles[i].Friction(0.996);
            particles[i].Move(screenWidth, screenHeight);

        }
        
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircleV(five_pos, 10 , BLACK);

        for(int i = 0; i < particleCount; i++)
        {
            particles[i].Draw();
        }

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    MemFree(particles);

    return 0;
}