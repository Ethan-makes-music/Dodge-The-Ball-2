#include <iostream>
#include <raylib.h>

using namespace std;

class Ball
{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        Texture2D ballSprite = LoadTexture("assets/ball.png");
        DrawTexture(ballSprite, x, y, WHITE);
    }
};

class Player
{
    public:
    float x = 100;
    float y = 100;
    int speed_x = 7;
    int speed_y = 7;
    int radius = 46;

    void Draw()
    {
        Texture2D playerSprite = LoadTexture("assets/player.png");
        DrawTexture(playerSprite, x, y, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        {
            y = y - speed_y;
        }
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        {
            y = y + speed_y;
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        {
            x = x - speed_x;
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        {
            x = x + speed_x;
        }
    }
};

class MenuImage
{
    public:
    float x, y;

    void Draw()
    {
        Texture2D menuSprite = LoadTexture("assets/titleMenu.png");
        DrawTexture(menuSprite, x, y, WHITE);
    }
};

class PauseImage
{
    public:
    float x, y;

    void Draw()
    {
        Texture2D pauseSprite = LoadTexture("assets/paused.png");
        DrawTexture(pauseSprite, x, y, WHITE);
    }
};

class NextLevelImage
{
    public:
    float x, y;

    void Draw()
    {
        Texture2D nextlevelImage = LoadTexture("assets/nextLevel.png");
        DrawTexture(nextlevelImage, x, y, WHITE);
    }
};

class DeadImage
{
    public:
    float x, y;

    void Draw()
    {
        Texture2D deadImage = LoadTexture("assets/uDed.png");
        DrawTexture(deadImage, x, y, WHITE);
    }
};

class WinImage
{
    public:
    float x, y;

    void Draw()
    {
        Texture2D winImage = LoadTexture("assets/winSigma.png");
        DrawTexture(winImage, x, y, WHITE);
    }
};

Player player;
Ball ball;
MenuImage menuimage;
PauseImage pauseimage;
NextLevelImage levelImage;
DeadImage deadImage;
WinImage winImage;

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

    ball.radius = 38;
    ball.x = 200;
    ball.y = 200;
    if (level == 1)
    {
        ball.speed_x = 7;
        ball.speed_y = 7;
    }
    else if (level == 2)
    {
        ball.speed_x = 0;
        ball.speed_y = 0;
    }

    player.radius = 46;
    player.x = screenWidth/2;
    player.y = screenHeight/2;

    player.speed_x = 7;
    player.speed_y = 7;

    menuimage.x = 88;
    menuimage.y = 69;

    pauseimage.x = 27;
    pauseimage.y = 141;

    levelImage.x = 179;
    levelImage.y = 145;

    deadImage.x = 186;
    deadImage.y = 95;

    winImage.x = 186;
    winImage.y = 116;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(ball.x + ball.radius >= screenWidth  || ball.x - ball.radius <= 0)
        {
            PlaySound(nonHit);
            ball.speed_x *= -1;
            score = score + 1;
            std::cout << score;
        }

        if(ball.y + ball.radius >= screenHeight  || ball.y - ball.radius <= 0)
        {
            PlaySound(nonHit);
            ball.speed_y *= -1;
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
            ball.x += ball.speed_x;
            ball.y += ball.speed_y;

            player.Draw();
            player.Update();

            if (CheckCollisionCircles(Vector2{ball.x, ball.y}, ball.radius, Vector2{player.x, player.y}, player.radius))
            {
                state = "dead";
                PlaySound(hit);
            }

            ball.Draw();
            DrawText(TextFormat("Score: %i", score), 0, 0, 32, BLACK);
        }
        else if (state == "menu")
        {
            menuimage.Draw();
        }
        else if (state == "paused")
        {
            pauseimage.Draw();
        }
        else if (state == "nxtLevel")
        {
            levelImage.Draw();
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
            deadImage.Draw();
            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(hit);
                score = 0;
                ball.radius = 38;
                ball.x = 200;
                ball.y = 200;

                player.radius = 46;
                player.x = screenWidth/2;
                player.y = screenHeight/2;

                player.speed_x = 7;
                player.speed_y = 7;
                level = 1;
                state = "menu";
            }
        }
        else if (state == "win")
        {
            winImage.Draw();

            if (IsKeyPressed(KEY_ENTER))
            {
                PlaySound(hit);
                score = 0;
                ball.radius = 38;
                ball.x = 200;
                ball.y = 200;

                player.radius = 46;
                player.x = screenWidth/2;
                player.y = screenHeight/2;

                player.speed_x = 7;
                player.speed_y = 7;
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