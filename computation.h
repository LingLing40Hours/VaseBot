#ifndef COMPUTATION_H
#define COMPUTATION_H

#include <avz.h>


double stabilizingDPSBack(int row);
double stabilizingDPSFront(int row);
int totalHealthToHouse(int row);
bool isStable(int row,
    std::vector<AZombie*>& pZombies, double* zombieAbscissas, double* zombieHealths, double* slownessCDs, int zombieCount,
    std::vector<APlant*>& pPlants, double* plantAbscissas, double* plantHealths, int plantCount); // recursive
bool willSquash(int tile_x, double zombieAbscissa);

void convergeDelayTimeAndPoint(double range, std::vector<AZombie*> zombies, double &delayTime, double &point);
bool convergeLawnWalnut(double range, std::vector<AZombie*> zombies);
double convergePointLawn(double range, std::vector<AZombie*> zombies);


int totalHealthToHouse(int row) {
    return 0;
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

bool willSquash(int tile_x, double zombieAbscissa) {
    return false;
}

//total obstacle health required to force zombies to converge within range
void convergeDelayTimeAndPoint(double range, std::vector<AZombie*> zombies, double &delayTime, double &point) {

}

bool convergeLawnWalnut(double range, std::vector<AZombie*> zombies) {
    return false;
}

//assumes no plant obstruction
//return -inf if no lawn convergence
double convergePointLawn(double range, std::vector<AZombie*> zombies) {
    if (zombies.size() == 1 && zombies[0]->Abscissa() > HOUSE_X0) {
        return zombies[0]->Abscissa();
    }

    

    return 0;
}

#endif