#include "player.hpp"

void Draw(PlayerInfo playerInfo)
{
    Texture2D playerSprite = LoadTexture("assets/player.png");
    DrawTexture(playerSprite, playerInfo.x, playerInfo.y, WHITE);
}

void Update(PlayerInfo* playerInfo)
{
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        playerInfo->y -= playerInfo->speed_y;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        playerInfo->y += playerInfo->speed_y;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        playerInfo->x -= playerInfo->speed_x;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        playerInfo->x += playerInfo->speed_x;
    }
}