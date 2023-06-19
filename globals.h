#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <avz.h> // 包含本框架的头文件

#define TARGET_LEVEL 200
#define WARMUP_L0 0
#define OPENING_L0 10
#define MIDGAME_L0 30
#define STOP_MUSIC_L0 MIDGAME_L0
#define MOUSE_CD 20 //in cs

#define VASE_X0 2
#define LAWN_WIDTH 9
#define LAWN_HEIGHT 5
#define LAWN_AREA (LAWN_WIDTH*LAWN_HEIGHT)
#define HOUSE_X0 -100.0

struct Zombie {
    double x;
    double speed;
    double health;
    double duangCD;
    double slownessCD;
};


//ALogger<AConsole> consoleLogger;
//ALogger<APvzGui> pvzGUILogger;
ALogger<AMsgBox> msgBoxLogger;
ATickRunner tickRunner;
int regularPeaDamage = AMRef<int>(0x69f1c8);
int snowPeaDamage = AMRef<int>(0x69f1d4);
int plantHealth = AMRef<int>(0x45dc55);
int walnutHealth = AMRef<int>(0x45e1a7);

#endif