#include <avz.h> // 包含本框架的头文件

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

void getRowZombies(int row, std::vector<AZombie*>& pZombies)
{
    // AAliveFilter<AZombie> zombieFilter;
    for (auto& zombie : aAliveZombieFilter) {
        if (zombie.Row() == row) {
            AZombie* pZombie = &zombie;
            pZombies.push_back(pZombie);
        }
    }
}

// recurse upon zombie death, plant death, zombie reach plant
// end upon zombie reach house
bool isStable(int row,
    std::vector<AZombie*>& pZombies, double* zombieAbscissas, double* zombieHealths, double* slownessCDs, int zombieCount,
    std::vector<APlant*>& pPlants, double* plantAbscissas, double* plantHealths, int plantCount)
{
    for (AZombie*& pZombie : pZombies) {
        int plant_left = 0;
        int plant_right = 0;
        if (pZombie->AttackAbscissa() > plant_left && pZombie->AttackAbscissa() < plant_right) {
            // plant under attack
        }
    }
    return true;
}