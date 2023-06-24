/*
    A Vasebreaker Endless bot.
    Before injection, open pvzToolkit and turn on auto-collect and no-drops
*/
#include <avz.h>    // 包含本框架的头文件
#include <vector>
#include "globals.h"
#include "computation.h"
#include "input.h"
#include "output.h"


ACoroutine warmupStrategy(bool *pDone);
ACoroutine openingStrategy(bool *pDone);
ACoroutine midgameStrategy(bool *pDone);


ACoroutine ACoScript() {
    ASetReloadMode(AReloadMode::MAIN_UI);
    aItemCollector.Pause(); //sun collection handled by pvz toolkit

    //wait
    AWaitForFight();
    co_await [] { return !AGameIsPaused(); };

    //game loop
    int level = currentLevel();
    while (level < TARGET_LEVEL) {
        //turn off bgm
        if (level == STOP_MUSIC_L0) {
            stopMusic();
        }

        //run strategy
        bool coDone = false; bool *pCoDone = &coDone;
        if (level >= WARMUP_L0 && level < OPENING_L0) {
            ACoLaunch(std::bind(warmupStrategy, pCoDone));
        }
        else if (level >= OPENING_L0 && level < MIDGAME_L0) {
            ACoLaunch(std::bind(openingStrategy, pCoDone));
        }
        else {
            ACoLaunch(std::bind(midgameStrategy, pCoDone));
        }
        co_await [=] { return *pCoDone; };
        
        //wait for level change
        co_await [=] { return currentLevel() != level; };
        level = currentLevel();
    }

    /*
    AConnect('Q', breakAllOriginal);

    bool *dontCare;
    AConnect('W', std::bind(breakAll, dontCare, false, true, false));
    */
    co_return;
}


//converge on potato mine
//potato mine right of walnut
//if front zombies too fast, use a single snow pea
//potato mine can obstruct during activation phase
//squash can obstruct during targeting phase
//snow pea to slow more than one zombie?
//finish obstructing as early as possible
//kill as late as possible

//ensuring all health is consumed and zombies converge, choose convergence points as far left as possible
//t = when last zombie reaches convergence point
//x = 
//sacrificial plants (for multisquash, multimine)
ACoroutine warmupStrategy(bool *pDone) {
    //break all
    bool coDone = false; bool *pCoDone = &coDone;
    ACoLaunch(std::bind(breakAll, pCoDone, false, true, false));
    co_await [=] { return *pCoDone; };

    //get zombie pointers by row
    std::vector<std::vector<AZombie*>> zombies(LAWN_TILE_HEIGHT, std::vector<AZombie*>());
    for (auto &zombie : aAliveZombieFilter) {
        zombies[zombie.Row()].push_back(&zombie);
    }

    std::vector<double> convergencePoints(LAWN_TILE_HEIGHT, 0);
    
    for (int row=0; row < LAWN_TILE_HEIGHT; ++row) {
        //do stuff


        //remove dead zombie pointers
        std::vector<AZombie*> &rowZombies = zombies[row];
        for (int zombieItr=rowZombies.size()-1; zombieItr >= 0; --zombieItr) {
            if (rowZombies[zombieItr]->IsDead()) {
                rowZombies.erase(rowZombies.begin()+zombieItr);
            }
        }

    }

    tickRunner.Start([] {
        for (auto &zombie : aAliveZombieFilter) {
            msgBoxLogger.Error(zombie.Speed());
            break;
        }
    });

    *pDone = true;
}

//swag as many squash as possible
ACoroutine openingStrategy(bool *pDone) {
    bool coDone = false; bool *pCoDone = &coDone;
    ACoLaunch(std::bind(breakAll, pCoDone, false, true, false));
    co_await [=] { return *pCoDone; };
    bool stable = false;

    while (!stable) {
        //update stability
    }

    //swag squash (in w pattern) and plantern

    *pDone = true;
}

//optimal play
ACoroutine midgameStrategy(bool *pDone) {
    int vaseCount = initialVaseCount();
    bool stable = true;
    while (vaseCount != 0 || !stable) {

    }

    *pDone = true;
    co_return;
}