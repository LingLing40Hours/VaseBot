#ifndef COMPUTATION_H
#define COMPUTATION_H

#include <avz.h>


bool isStable(int row,
    std::vector<AZombie*>& pZombies, double* zombieAbscissas, double* zombieHealths, double* slownessCDs, int zombieCount,
    std::vector<APlant*>& pPlants, double* plantAbscissas, double* plantHealths, int plantCount); // recursive
bool willSquash(int tile_x, double zombieAbscissa);


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

bool willSquash(int tile_x, double zombieAbscissa) {
    return false;
}

#endif