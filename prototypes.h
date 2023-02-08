#include "definitions.h"
#include <avz.h> // 包含本框架的头文件

void breakVase(int tile_x, int tile_y);
void breakAll(int* counter);
int currentLevel();
bool isStable(int row,
    std::vector<AZombie*>& pZombies, double* zombieAbscissas, double* zombieHealths, double* slownessCDs, int zombieCount,
    std::vector<APlant*>& pPlants, double* plantAbscissas, double* plantHealths, int plantCount);
void getRowZombies(int row, std::vector<AZombie*>& pZombies);