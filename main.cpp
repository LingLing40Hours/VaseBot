#include <avz.h>    // 包含本框架的头文件
#include <vector>
#include "globals.h"
#include "computation.h"
#include "input.h"
#include "output.h"


ACoroutine openingStrategy();
ACoroutine midgameStrategy();

ACoroutine ACoScript() {

    ASetReloadMode(AReloadMode::MAIN_UI);
    aItemCollector.Pause(); //sun collection handled by pvz toolkit
    
    AConnect('Q', breakAllOriginal);

    AConnect('W', []() -> ACoroutine {
        bool done = false; bool *pdone = &done;
        ACoLaunch(std::bind(breakAll, pdone, true, true, true));
        co_await [=] { return *pdone; };
    });


    tickRunner.Start([] {
        // debug
        int y = 0;
        for (auto& zombie : aAliveZombieFilter) {
            if (zombie.Type() == AZOMBIE) {
                aPainter.Draw(AText("A Regular Zombie with speed " + std::to_string(zombie.Speed()), 200, y), 1);
                y += 20;
            }
        }
    });

    //game loop
    /*
    int level = 1;
    while (level <= TARGET_LEVEL) {
        if (level <= 30) {
            openingStrategy();
        }
        else {
            midgameStrategy();
        }
        
        //wait for level change
        while (currentLevel() == level) {
            //swag squash (in w pattern) and plantern
        }
        level = currentLevel();
    }*/
    co_return;
}


ACoroutine openingStrategy() {
    bool done = false; bool *pdone = &done;
    ACoLaunch(std::bind(breakAll, pdone, false, true, false));
    co_await [=] { return *pdone; };
    bool stable = false;

    while (!stable) {
        //update stability
    }
}

ACoroutine midgameStrategy() {
    int vaseCount = initialVaseCount();
    bool stable = true;
    while (vaseCount != 0 || !stable) {

    }
    co_return;
}