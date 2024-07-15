#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

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
    const int startPos = 640;
    int lock = false;
    int ammt = 0;

    struct pipe{
      int size;
      float position;
    };
    struct pipe pipes[ammt];
    pipes[0].size = 120;
    pipes[1].size = 220;
    pipes[1].position = startPos;
    pipes[0].position = startPos;
    while (!WindowShouldClose()) {
        asprintf(&pHolder, "%d ammt %d", (int)GetTime (), ammt);

        (velocity <= velocityCap) ? velocity += acceleration : false ;

        if(IsKeyPressed (KEY_SPACE) == true){
          birbPosition.y -= 13 * velocity * GetFrameTime ();
          velocity = 100.0f;
        }else{
          birbPosition.y += velocity * GetFrameTime ();
        }

        if ((int)GetTime ()%2 == 0 && lock == false) ammt +=1; lock = true;
        if ((int)GetTime ()%2 == 1) lock = false;
        BeginDrawing();
          ClearBackground (DARKGRAY);
          DrawText (pHolder, 0, 0, 30, LIME);
          DrawCircleV (birbPosition, 25.0f, BLUE);
          for(int i = 0; i < ammt; i++){
          pipes[i].position -= 100 * GetFrameTime ();
          DrawRectangle (pipes[i].position, 0, 58, pipes[i].size, LIME);
          DrawRectangle (pipes[i].position, GetScreenHeight () - pipes[i].size - 50, 58, pipes[i].size + 140, LIME);
          //printf ("%d",ammt);
          }
        EndDrawing();
    }
    CloseWindow();

  return 0;
    }


