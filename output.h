// output to game
#ifndef OUTPUT_H
#define OUTPUT_H

#include <avz.h> // 包含本框架的头文件
//#include <future>
#include "globals.h"


void breakVase(int tile_x, int tile_y);
ACoroutine breakAllUtil(bool *pdone, int x, int y, int x0, int y0, int x1, int y1, std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken);
ACoroutine breakAll(bool *pdone, bool xdir, bool ydir, bool rowMajor);
ACoroutine breakAllOriginal();
void findVases(std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken);
void updateVases(std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken);
void placeSeed(ASeed seed, int tile_y, int tile_x);


void breakVase(int tile_y, int tile_x) { // x rightwards from 1, y downwards from 1
    AClickGrid(tile_y, tile_x);
}

ACoroutine breakAllUtil(bool *pdone, int x, int y, int x0, int y0, int x1, int y1, std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken) {
    if (x != x0 || y != y0) {
        updateVases(vases, vaseBroken);
    }

    if (!vaseBroken[y][x]) {
        breakVase(y+1, x+1);

        int vaseCount = vases.size() - 1;
        if (vaseCount != 0) {
            co_await ANowDelayTime(MOUSE_CD);
        }
    }
    *pdone = true;
}

ACoroutine breakAll(bool *pdone, bool xdir, bool ydir, bool rowMajor) {
    std::vector<std::vector<bool>> vaseBroken = std::vector(LAWN_HEIGHT, std::vector(LAWN_WIDTH, true));
    std::vector<APlaceItem*> vases;

    //get vase pointers
    findVases(vases, vaseBroken);

    //find xy bounds
    int x0 = xdir ? VASE_X0 : LAWN_WIDTH-1;
    int y0 = ydir ? 0 : LAWN_HEIGHT-1;
    int x1 = xdir ? LAWN_WIDTH : -1;
    int y1 = ydir ? LAWN_HEIGHT : -1;
    int dx = xdir ? 1 : -1;
    int dy = ydir ? 1 : -1;

    if (rowMajor) {
        for (int y=y0; y != y1; y += dy) {
            for (int x=x0; x != x1; x += dx) {
                bool done2 = false; bool *pdone2 = &done2;
                ACoLaunch(std::bind(breakAllUtil, pdone2, x, y, x0, y0, x1, y1, vases, vaseBroken));
                co_await [=] { return *pdone2; };
            }
        }
    }
    else {
        for (int x=x0; x != x1; x += dx) {
            for (int y=y0; y != y1; y += dy) {
                bool done2 = false; bool *pdone2 = &done2;
                ACoLaunch(std::bind(breakAllUtil, pdone2, x, y, x0, y0, x1, y1, vases, vaseBroken));
                co_await [=] { return *pdone2; };
            }
        }
    }
    *pdone = true;
}

ACoroutine breakAllOriginal() {
    for (int x = 9; x >= 3; --x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(y, x);
            co_await ANowDelayTime(MOUSE_CD);
        }
    }
}

void findVases(std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken) {
    for (auto &placeItem : aAlivePlaceItemFilter) {
        if (placeItem.MRef<int>(0x8) == 7) { //is vase
            vases.push_back(&placeItem);
            vaseBroken[placeItem.Row()][placeItem.Col()] = false;
        }
    }
}

void updateVases(std::vector<APlaceItem*> &vases, std::vector<std::vector<bool>> &vaseBroken) {
    for (int vaseItr=vases.size()-1; vaseItr >= 0; --vaseItr) {
        APlaceItem *vase = vases[vaseItr];
        if (vase->IsDisappeared()) {
            vaseBroken[vase->Row()][vase->Col()] = true;
            vases.erase(vases.begin()+vaseItr);
        }
    }
}

void placeSeed(ASeed seed, int tile_y, int tile_x) {
}

#endif