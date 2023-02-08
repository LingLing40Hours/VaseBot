#include "definitions.h"
#include <avz.h> // 包含本框架的头文件

// output to game
void breakVase(int tile_x, int tile_y);
void breakAll(int* counter);

// input from game
int currentLevel();
void getRowZombies(int row, std::vector<AZombie*>& pZombies);
void getSeeds();

bool jackExploded();
void getRemainingSeeds();
void getRemainingZombies();

// computation
bool isStable(int row,
    std::vector<AZombie*>& pZombies, double* zombieAbscissas, double* zombieHealths, double* slownessCDs, int zombieCount,
    std::vector<APlant*>& pPlants, double* plantAbscissas, double* plantHealths, int plantCount); // recursive
bool willSquash(int tile_x, double zombieAbscissa);
