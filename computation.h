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

double hurtboxLeft(AZombie* pZombie);
double hurtboxRight(AZombie* pZombie);
double hitboxLeft(AZombie* pZombie);
double hitboxRight(AZombie* pZombie);
RRange convergeRangeAny(double hitboxRange, std::vector<AZombie*> zombies);
RRange convergeRangeCenter(double hitboxRange, std::vector<AZombie*> zombies);
RRange convergeRangeLeft(double hitboxRange, std::vector<AZombie*> zombies);
RRange convergeRangeRight(double hitboxRange, std::vector<AZombie*> zombies);


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

//total delay time required to force zombies to converge within range
void convergeDelayTimeAndPoint(double range, std::vector<AZombie*> zombies, double &delayTime, double &point) {

}

bool convergeLawnWalnut(double range, std::vector<AZombie*> zombies) {
    return false;
}

double hurtboxLeft(AZombie* pZombie) {
    return pZombie->Abscissa() + pZombie->BulletAbscissa();
}

double hurtboxRight(AZombie* pZombie) {
    return hurtboxLeft(pZombie) + pZombie->HurtWidth();
}

double hitboxLeft(AZombie* pZombie) {
    return pZombie->Abscissa() + pZombie->AttackAbscissa();
}

double hitboxRight(AZombie* pZombie) {
    return hitboxLeft(pZombie) + pZombie->MVal<int>(0xa4);
}

//the following functions assume no plant obstruction
    //range of convergence points c where all hitboxes overlap with [c, c+hitboxRange]
    //range of convergence points c where all hitbox centers within [c, c+hitboxRange]
    //range of convergence points c where all hitbox left edges within [c, c+hitboxRange]
    //range of convergence points c where all hitbox right edges within [c, c+hitboxRange]
RRange convergeRangeAny(double hitboxRange, std::vector<AZombie*> zombies) {
    if (zombies.size() == 0) {
        return RRange(N_INF, P_INF);
    }

    AZombie* first = zombies[0];
    double v1 = first->Speed();
    double x1Left = hurtboxLeft(first);
    double x1Right = hurtboxRight(first);
    RRange ans(N_INF, x1Right);

    for (std::vector<AZombie*>::iterator it = zombies.begin()+1; it != zombies.end(); ++it) {
        RRange pairRange = RRange(
    }
}

RRange convergeRangeCenter(double hitboxRange, std::vector<AZombie*> zombies);
RRange convergeRangeLeft(double hitboxRange, std::vector<AZombie*> zombies);
RRange convergeRangeRight(double hitboxRange, std::vector<AZombie*> zombies);

#endif