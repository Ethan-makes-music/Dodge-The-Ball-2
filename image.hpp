#include <raylib.h>
#include <iostream>

typedef struct
{
    float xB, yB;
    int speed_xB, speed_yB;
    int radiusB;
}BallInfo;

typedef struct
{
    float xMI, yMI;
    float xPI, yPI;
    float xNLI, yNLI;
    float xUD, yUD;
    float xWI, yWI;
}AllImages;

void DrawBall(BallInfo ballInfo);
void DrawMI(AllImages image);
void DrawPI(AllImages image);
void DrawNLI(AllImages image);
void DrawUD(AllImages image);
void DrawWI(AllImages image);