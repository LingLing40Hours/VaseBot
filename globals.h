#ifndef GLOBALS_H
#define GLOBALS_H

#include <avz.h> // 包含本框架的头文件
#include "rrange.h"

#define TARGET_LEVEL 200
#define WARMUP_L0 0
#define OPENING_L0 10
#define MIDGAME_L0 30
#define STOP_MUSIC_L0 MIDGAME_L0
#define MOUSE_CD 20 //in cs

#define VASE_X0 2
#define LAWN_TILE_WIDTH 9
#define LAWN_TILE_HEIGHT 5
#define LAWN_TILE_AREA (LAWN_TILE_WIDTH*LAWN_TILE_HEIGHT)

#define GAME_WIDTH 800
#define GAME_HEIGHT 600
#define HOUSE_X0 -100 //min zombie x upon death
#define TILE_WIDTH 80
#define TILE_HEIGHT 100

struct Coord {
    double x = 0;
    double y = 0;

    Coord(double tx, double ty) : x(tx), y(ty) {}
}

struct Zombie {
    double x;
    double speed;
    double health;
    double duangCD;
    double slownessCD;
};

//aggro/attack data
//triggers are relative to plant xy + (40, 40);
double brepeaterXOffset = -60;

RRange potatoTrigger(-40, 15);
double potatoEatingExtend = 30; //in both directions
double potatoPVLeftContract = 40;
Coord potatoAttackOffset(-15, 0);
double potatoAttackRadius = 55;
int potatoChargeTime = 1500; //cs
int potatoRiseTime = 106; //cs

double squashAttackWidth = 43;
RRange squashTrigger(-20, 95);
double squashEatingRightExtend = 40; //if eating
double squashMiscLeftExtend = 60; //polevault, dolphin, football, imp
double squashRightwardLeftExtend = 70;
double squashRightwardEatingLeftExtend = 110; //relative to squashTrigger
RRange squashTriggerRunningPV(-98, 3);
double squashFootballRelativeExtend = 20; //in both directions
int squashJumpTime = 127; //cs after trigger
int squashAttackTime = 181; //cs after trigger

//damage/health data
int regularPeaDamage = AMRef<int>(0x69f1c8);
int snowPeaDamage = AMRef<int>(0x69f1d4);
int plantHealth = AMRef<int>(0x45dc55);
int walnutHealth = AMRef<int>(0x45e1a7);

//hitbox/hurtbox offset data
//get from zombie pointer

//loggers
//ALogger<AConsole> consoleLogger;
//ALogger<APvzGui> pvzGUILogger;
ALogger<AMsgBox> msgBoxLogger;
ATickRunner tickRunner;

#endif