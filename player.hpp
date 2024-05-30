#include <raylib.h>
#include <iostream>

typedef struct
{
    float x, y;
    int speed_x, speed_y, radius;
}PlayerInfo;

void Draw(PlayerInfo playerInfo);
void Update(PlayerInfo* playerInfo);