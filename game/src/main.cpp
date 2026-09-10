/*
This project uses the Raylib framework to provide us functionality for math, graphics, GUI, input etc.
See documentation here: https://www.raylib.com/, and examples here: https://www.raylib.com/examples.html
*/

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

const unsigned int TARGET_FPS = 50;
float time = 0;
int main()
{
    InitWindow(1200, 800," lab 1- game2005");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText("Thomas Alves ID:101422210", 10, 10, 20, LIGHTGRAY);


            time += 1;

            GuiSliderBar(Rectangle{ 60, 5, 1000, 10 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
            //set up a iretive game loop with a repeting update function, also render time on the top right of the window.
            //move and object which starts at a given postion and moves each fram acorrding to the equations from the lap overview. 

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            EndDrawing();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
