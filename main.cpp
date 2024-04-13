#include <iostream>
#include <raylib.h>

#include "points_on_screen.h"
using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 800;

    points_on_screen* myPointsOnScreen = new points_on_screen;

    //Brought into points_on_screen (1)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
    Vector2 circleCenter = {screenWidth/2, screenHeight/2};
    float radius = 175.0f;
    float angle = 0.0f;
    float speed = 0.01f;
    */
    //New Code(1)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // It is implemented in the the Game Loop
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#


    //Brought into points_on_screen(2)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
    Vector2 one_pos = {400, 225};
    Vector2 two_pos = {276.2563133, 523.7436867};
    Vector2 three_pos = {523.7436867, 523.7436867};
    */
    //New Code(2)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //It is implemented in the Game Loop
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

    SetRandomSeed(1);

    //Brought into points_on_screen(3)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
    const int particleCount = 100000;
    Particle *particles = (Particle*)malloc(particleCount * sizeof(Particle));

    for(long int i = 0; i < particleCount; i++)
    {
        particles[i] = Particle(screenWidth, screenHeight);
    }
    */
    //New Code(3)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    myPointsOnScreen -> particle_init();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

    InitWindow(screenWidth, screenHeight, "Particles");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        
    //    Vector2 four_pos = {(float)GetMouseX(), (float)GetMouseY()};

    //Brought into points_on_screen(4)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
        angle += speed;

        float x = circleCenter.x + radius *cosf(angle);
        float y = circleCenter.y + radius *sinf(angle);
        Vector2 five_pos = {x, y};
    */
    //New Code(4)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

    //Brought into points_on_screen(5)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
        for(long int i = 0; i < particleCount; i++)
        {

            particles[i].Attract(one_pos, 2.5);
            particles[i].Attract(two_pos, 2.5);
            particles[i].Attract(three_pos, 2.5);
            particles[i].Attract(four_pos, 1.5);
            particles[i].Attract(five_pos, 5);
            particles[i].Friction(0.997);
            particles[i].Move(screenWidth, screenHeight);

        }
    */
    //New Code(5)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        myPointsOnScreen -> presetOne();
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
        
        BeginDrawing();
        ClearBackground(BLACK);

    //Brought into points_on_screen(6)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /*
        DrawCircleV(five_pos, 10 , BLACK);

        for(int i = 0; i < particleCount; i++)
        {
            particles[i].Draw(i);
        }
    */
    //New Code(6)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    myPointsOnScreen -> particles_Draw();
    myPointsOnScreen -> circle_Draw();

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
    //Brought into points_on_screen(7)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //MemFree(particles);
    //New Code(7)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    delete myPointsOnScreen;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

    return 0;
}