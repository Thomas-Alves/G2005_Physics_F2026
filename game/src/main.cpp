/*
This project uses the Raylib framework to provide us functionality for math, graphics, GUI, input etc.
See documentation here: https://www.raylib.com/, and examples here: https://www.raylib.com/examples.html
*/

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
//target fps
const unsigned int TARGET_FPS = 50;
//screen dimentions 
int screenHeight = 800;
int screenWidth = 1200;

//launch, speed, angle
Vector2 launchPosition;
float launchSpeed = 100.0f;
float launchAngle = 0.0f;
float LaunchAngleAdjustmentSpeed = 50.0f;
Vector2 velocity;

//bird start postion 
Vector2 birdPosition;

//amplitude 
float b = 100;

//frequency 
float a = 100;

//time 
float time = 0;


int main()
{
    InitWindow(screenWidth, screenHeight," lab 1- game2005");
    SetTargetFPS(TARGET_FPS);
    //birdPosition = { 30, (float)(screenHeight - 50) };
    launchPosition = { 30, (float)(screenHeight - 50) };
    

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawText("Thomas Alves ID:101422210", 10, 780, 15, BLACK);


        // start back video(JOSS LAB ONLINE) at 1:08:00 

        GuiSlider(Rectangle{ 5, 5, 100, 20 }, "launchSpeed", TextFormat("%.2f", launchSpeed), &launchSpeed, 1, 500);
        GuiSlider(Rectangle{ 5, 30, 100, 20 }, "launchAngle", TextFormat("%.2f", launchAngle), &launchAngle, 0, 90);
        
        if (IsKeyDown(KEY_UP)) {
            launchPosition.y -= LaunchAngleAdjustmentSpeed * GetFrameTime();

        } if (IsKeyDown(KEY_DOWN)) {
            launchPosition.y += LaunchAngleAdjustmentSpeed * GetFrameTime();
        }
            
        velocity = { launchSpeed, 0 };
        DrawCircleV(launchPosition, 10, RED);
        DrawLineEx(launchPosition, launchPosition + velocity, 1, BLACK);
            

            EndDrawing();
    }

    CloseWindow();
    return 0;
}
