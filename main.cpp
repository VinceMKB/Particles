#include <iostream>
#include <raylib.h>

#include "points_on_screen.h"
using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 800;

    points_on_screen* myPointsOnScreen = new points_on_screen;

    SetRandomSeed(1);
    myPointsOnScreen -> particle_init();

    int current_preset = 1;
    InitWindow(screenWidth, screenHeight, "Particles");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        
        //myPointsOnScreen -> presetOne();

        if (IsKeyDown(KEY_KP_1) || IsKeyDown(KEY_KP_2) || IsKeyDown(KEY_KP_3)||IsKeyDown(KEY_KP_4)) 
        {
            switch (GetKeyPressed()) 
            {
                case KEY_KP_1:
                    current_preset = 1;
                    break;
                case KEY_KP_2:
                    current_preset = 2;
                    break;
                case KEY_KP_3:
                    current_preset = 3;
                    break;
                case KEY_KP_4:
                    current_preset = 4;
                    break;   
            }
        }
        

        switch (current_preset) 
        {
            case 1:
                myPointsOnScreen -> presetOne();
                break;
            case 2:
                myPointsOnScreen -> presetTwo();
                break;
            case 3:
                myPointsOnScreen -> presetThree();
                break;
            case 4:
                myPointsOnScreen -> presetFour();
                break;
            default:
                myPointsOnScreen -> presetOne();
                break;
        }
        
        BeginDrawing();
        ClearBackground(BLACK);

        myPointsOnScreen -> particles_Draw();

        if(current_preset == 1)  
        {
            myPointsOnScreen -> circle_Draw();
        }

        if(current_preset == 2)
        {
            myPointsOnScreen -> square_Draw();
        }

        DrawText("NumericKeyPad Presets: PresetOne(Default on '1'), PresetTwo(on '2'), PresetThree(on '3')", 10, 780, 15, GREEN);
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    delete myPointsOnScreen;

    return 0;
}