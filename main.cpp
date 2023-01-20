#include <avz.h> // 包含本框架的头文件
#include <stdlib.h>

void breakVase(int tile_x, int tile_y);
void breakAll(int* counter);
int currentLevel();
bool isStable(int row);
void getRowZombies(int row, std::vector<AZombie>& zombies);

ALogger<AMsgBox> logger;
ATickRunner tickRunner;

int vaseCounter = -1;
int* pVaseCounter = &vaseCounter;
int MOUSE_CD = 20; // at least 20 for vase breaking

void AScript()
{
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    // aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    AConnect('Q', [] {
        breakAll(pVaseCounter);
        // logger.Info("current level: #", currentLevel());
    });

    tickRunner.Start([] {
        // break vase
        if (vaseCounter >= 0) {
            if (vaseCounter % MOUSE_CD == 0) {
                int tx = (vaseCounter / MOUSE_CD) / 5 + 3;
                int ty = 5 - (vaseCounter / MOUSE_CD) % 5;
                breakVase(ty, tx);
            }
            --vaseCounter;
        }

        AAliveFilter<AZombie> zombieFilter;
        int y = 0;
        for (auto&& zombie : zombieFilter) {
            if (zombie.Type() == AZOMBIE) {
                aPainter.Draw(AText("A Regular Zombie with speed " + std::to_string(zombie.Speed()), 200, y), 1);
                y += 20;
            }
        }
        aPainter.Draw(AText("vaseCounter: " + std::to_string(vaseCounter), 50, 10), 1);
    });
}

void breakVase(int tile_y, int tile_x)
{ // x rightwards from 1, y downwards from 1
    AClickGrid(tile_y, tile_x);
}

void breakAll(int* pVaseCounter)
{
    /*
    for (int x = 9; x >= 3; --x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(y, x);
        }
    }*/
    *pVaseCounter = 34 * MOUSE_CD;
}

int currentLevel() // int 0x6C, 0x160, 0x768, 0x6A9EC0
{
    return AGetPvzBase()->MPtr<APvzStruct>(0x768)->MPtr<APvzStruct>(0x160)->MRef<int>(0x6c);
}

// recurse upon zombie death, plant death, zombie reach plant
// end upon zombie reach house
/*
bool isStable(int row,
    std::vector<AZombie>& zombies, double* zombieAbscissas, int zombieCount,
    std::vector<APlant>& plants, double* plantHealths, int plantCount)
{
    std::vector<AZombie> zombies = rowZombies(row);
    for (AZombie zombie : zombies) {
        if (zombie.AttackAbscissa() > plant_left && zombie.AttackAbscissa() < plant_right) {
            // plant under attack
        }
    }
    return true;
}*/

/*
void getRowZombies(int row, std::vector<AZombie>& zombies)
{
    AAliveFilter<AZombie> zombieFilter;
    for (auto&& zombie : zombieFilter) {
        if (zombie.Row() == row) {
            zombies.push_back(zombie);
        }
    }
}*/