// This file is mainly just for images that dont really need update functions
#include "image.hpp"

void DrawBall(BallInfo ballInfo)
{
    Texture2D ballSprite = LoadTexture("assets/ball.png");
    DrawTexture(ballSprite, ballInfo.xB, ballInfo.yB, WHITE);
}

void DrawMI(AllImages image)
{
    Texture2D menuSprite = LoadTexture("assets/titleMenu.png");
    DrawTexture(menuSprite, image.xMI, image.yMI, WHITE);
}

void DrawPI(AllImages image)
{
    Texture2D pauseSprite = LoadTexture("assets/paused.png");
    DrawTexture(pauseSprite, image.xPI, image.yPI, WHITE);
}

void DrawNLI(AllImages image)
{
    Texture2D nextlevelImage = LoadTexture("assets/nextLevel.png");
    DrawTexture(nextlevelImage, image.xNLI, image.yNLI, WHITE);
}

void DrawUD(AllImages image)
{
    Texture2D deadImage = LoadTexture("assets/uDed.png");
    DrawTexture(deadImage, image.xUD, image.yUD, WHITE);
}

void DrawWI(AllImages image)
{
    Texture2D winImage = LoadTexture("assets/winSigma.png");
    DrawTexture(winImage, image.xWI, image.yWI, WHITE);
}