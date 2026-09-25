/*
This project uses the Raylib framework to provide us functionality for math, graphics, GUI, input etc.
See documentation here: https://www.raylib.com/, and examples here: https://www.raylib.com/examples.html
*/

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <vector>
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

//bird (struct to hold postion and veloctiy state (lab2) 
struct PhyscicsBody
{
public:
    Vector2 position = Vector2{ 0, 0 };
    Vector2 velocity = Vector2{ 0, 0 };
    Color color = RED;
    float radius = 10.0f;

};
// class to contain global properties of physics simulation, and to opertate on them each frame 
class PhysicsSimulation 
{
public:
    std::vector<PhyscicsBody> bodies; // a contatianer for all PhysicsBody in the simulation
    Vector2 gravity = { 0, 100 }; //Global acceleration due to gravity, in pixels/second/second
    const float FIXED_DELTA_TIME = 1.0f / (float)TARGET_FPS;//fixed delta time veraible for physics simulations


    void Update() 
    {
        for (int i = 0; i < bodies.size(); i++)
        {
            //PhyscicsBody body = bodies[i];
            //velocity is defind in pixels/seconds (we need pixels/frame)
            bodies[i].position += bodies[i].velocity * FIXED_DELTA_TIME;
            //acceleration is change in velocity over time, gravity is our acceleration in pixels/sec/sec (px/sec^2
            bodies[i].velocity += gravity * FIXED_DELTA_TIME;
        }
    }

    void Draw() 
    {
        for (int i = 0; i < bodies.size(); i++)
        {
            DrawCircleV(bodies[i].position, bodies[i].radius, bodies[i].color);
        }

    }
};

//PhyscicsBody bird;// = { Vector2{-1000, -1000}, Vector2{0,0} };
 PhysicsSimulation sim;


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
        DrawRectangle(0, 0, 400, 600, Color{ 0, 0, 0, 50 });

        GuiSlider(Rectangle{ 5, 5, 100, 20 }, "launchSpeed", TextFormat("%.2f", launchSpeed), &launchSpeed, 1, 500);
        GuiSlider(Rectangle{ 5, 30, 100, 20 }, "launchAngle", TextFormat("%.2f", launchAngle), &launchAngle, -90, 0);
        GuiSlider(Rectangle{ 5, 60, 100, 20 }, "gravity", TextFormat("%.2f", sim.gravity.y), &sim.gravity.y, -500, 500);

        if (IsKeyDown(KEY_UP)) {
            launchPosition.y -= LaunchAngleAdjustmentSpeed * GetFrameTime();

        } if (IsKeyDown(KEY_DOWN)) {
            launchPosition.y += LaunchAngleAdjustmentSpeed * GetFrameTime();
        }

        Vector2 velocityPreview = { cosf(launchAngle * DEG2RAD) * launchSpeed, sinf(launchAngle * DEG2RAD) * launchSpeed }; // use speed and angle 
        DrawCircleV(launchPosition, 10, RED);
        DrawLineEx(launchPosition, launchPosition + velocityPreview, 2, RED);

        //lab2 stuff
        if (IsKeyPressed(KEY_SPACE)) 
        {
            PhyscicsBody birdToLaunch;
            birdToLaunch.color = RED;
            birdToLaunch.radius = 10.0f;
            birdToLaunch.position = launchPosition;
            birdToLaunch.velocity = velocityPreview;

            sim.bodies.push_back(birdToLaunch);
        }

        sim.Update();
        sim.Draw();
        
            
            

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
