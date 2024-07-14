#include "raylib.h"
#include <stdio.h>

int main(void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;
    SetTargetFPS (60);
    InitWindow(screenWidth, screenHeight, "Flappy Birb");

    Vector2 birbPosition = {GetScreenWidth ()/2.0f, GetScreenHeight ()/4.0f};
    const int acceleration = 10.0f;
    float velocity = 10.0f;
    const int velocityCap = 300;
    char *pHolder;

    while (!WindowShouldClose()) {
        asprintf(&pHolder, "%d", GetFPS ());

        (velocity <= velocityCap) ? velocity += acceleration : false ;

        if(IsKeyPressed (KEY_SPACE) == true){
          birbPosition.y -= 13 * velocity * GetFrameTime ();
          velocity = 100.0f;
        }else{
          birbPosition.y += velocity * GetFrameTime ();
        }

        BeginDrawing();
          ClearBackground (DARKGRAY);
          DrawText (pHolder, 0, 0, 30, LIME);
          DrawCircleV (birbPosition, 25.0f, BLUE);
        EndDrawing();
    }
    CloseWindow();

  return 0;
    }


