#include <iostream>
#include <raylib.h>
#include "player.hpp"
#include "image.hpp"

using namespace std;

int main () 
{

    const int screenWidth = 800;
    const int screenHeight = 600;

    int score = 0;
    int level = 1;

    std::string state = "menu";

    InitWindow(screenWidth, screenHeight, "Dodge the ball 2");
    InitAudioDevice();
    Sound hit = LoadSound("assets/hit.wav");
    Sound nonHit = LoadSound("assets/pickupCoin.wav");
    SetTargetFPS(60);

    BallInfo ballInfo;
    ballInfo.radiusB = 38;
    ballInfo.xB = 200;
    ballInfo.yB = 200;

    if (level == 1)
    {
        ballInfo.speed_xB = 7;
        ballInfo.speed_yB = 7;
    }

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        PlayerInfo playerInfo;
        playerInfo.speed_x = 7;
        playerInfo.speed_y = 7;
        playerInfo.radius = 46;

        AllImages image;
        image.xMI = 88;
        image.yMI = 69;

        image.xPI = 27;
        image.yPI = 141;

        image.xNLI = 179;
        image.xNLI = 145;

        image.xUD = 186;
        image.yUD = 95;

        image.xWI = 186;
        image.yWI = 116;

        if(ballInfo.xB + ballInfo.radiusB >= screenWidth  || ballInfo.xB - ballInfo.radiusB <= 0)
        {
            PlaySound(nonHit);
            ballInfo.speed_xB *= -1;
            score = score + 1;
            std::cout << score;
        }

        if(ballInfo.yB + ballInfo.radiusB >= screenHeight  || ballInfo.yB - ballInfo.radiusB <= 0)
        {
            PlaySound(nonHit);
            ballInfo.speed_yB *= -1;
            score = score + 1;
            std::cout << score;
        }

        if (IsKeyPressed(KEY_ENTER) && state == "menu")
        {
            state = "game";
            level = 1;
            PlaySound(hit);
        }
        else if (IsKeyPressed(KEY_P) && state == "game")
        {
            state = "paused";
            PlaySound(hit);
        }
        else if (IsKeyPressed(KEY_ENTER) && state == "paused")
        {
            state = "game";
            PlaySound(hit);
        }
        else if (IsKeyPressed(KEY_R))
        {
            CloseWindow();
            main();
            PlaySound(hit);
        }

        if (state == "game")
        {
            ballInfo.xB += ballInfo.speed_xB;
            ballInfo.yB += ballInfo.speed_yB;

            Draw(playerInfo);
            Update(&playerInfo);

            if (CheckCollisionCircles(Vector2{ballInfo.xB, ballInfo.yB}, ballInfo.radiusB, Vector2{playerInfo.x, playerInfo.y}, playerInfo.radius))
            {
                state = "dead";
                PlaySound(hit);
            }

            DrawBall(ballInfo);
            DrawText(TextFormat("Score: %i", score), 0, 0, 32, BLACK);
        }
        else if (state == "menu")
        {
            DrawMI(image);
        }
        else if (state == "paused")
        {
            DrawPI(image);
        }
        else if (state == "nxtLevel")
        {
            DrawNLI(image);
            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(hit);
                level = level + 1;
                score = 0;
                state = "game";
            }
        }
        else if (state == "dead")
        {
            DrawUD(image);
            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(hit);
                score = 0;
                ballInfo.radiusB = 38;
                ballInfo.xB = 200;
                ballInfo.yB = 200;

                level = 1;
                state = "menu";
            }
        }
        else if (state == "win")
        {
            DrawWI(image);

            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(hit);
                score = 0;
                ballInfo.radiusB = 38;
                ballInfo.xB = 200;
                ballInfo.yB = 200;

                level = 1;
                state = "menu";
            }
        }

        if (level == 10)
        {
            state = "win";
        }

        if (score == 50)
        {
            state = "nxtLevel";
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}