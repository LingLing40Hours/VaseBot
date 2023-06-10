// output to game
#ifndef OUTPUT_H
#define OUTPUT_H

#include <avz.h> // 包含本框架的头文件
#include "globals.h"


ACoroutine waitCS(int n);
void breakVase(int tile_x, int tile_y);
ACoroutine breakAll();
void placeSeed(ASeed seed, int tile_y, int tile_x);


ACoroutine waitCS(int n) {
    co_await ANowDelayTime(n);
    //consoleLogger.Error("wait # cs", n);
}

void breakVase(int tile_y, int tile_x) { // x rightwards from 1, y downwards from 1
    AClickGrid(tile_y, tile_x);
}

ACoroutine breakAll() {
    for (int x = 9; x >= 3; --x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(y, x);
            co_await ANowDelayTime(MOUSE_CD);
        }
    }
}

void placeSeed(ASeed seed, int tile_y, int tile_x) {
}

#endif