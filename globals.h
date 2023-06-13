#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <avz.h> // 包含本框架的头文件

#define TARGET_LEVEL 200
#define MOUSE_CD 20 //in cs
#define VASE_X0 2
#define LAWN_WIDTH 9
#define LAWN_HEIGHT 5
#define LAWN_AREA (LAWN_WIDTH*LAWN_HEIGHT)


//ALogger<AConsole> consoleLogger;
//ALogger<APvzGui> pvzGUILogger;
ALogger<AMsgBox> msgBoxLogger;
ATickRunner tickRunner;
int regularPeaDamage = AMRef<int>(0x69f1c8);
int snowPeaDamage = AMRef<int>(0x69f1d4);
int plantHealth = AMRef<int>(0x45dc55);
int walnutHealth = AMRef<int>(0x45e1a7);

#endif