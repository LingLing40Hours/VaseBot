// input from game
#ifndef INPUT_H
#define INPUT_H

#include <avz.h>


int currentLevel();
int initialVaseCount();
void getRowZombies(int row, std::vector<AZombie*>& pZombies);
void getSeeds();

bool jackExploded();
void getRemainingSeeds();
void getRemainingZombies();


int currentLevel() { // int 0x6C, 0x160, 0x768, 0x6A9EC0
    return AGetPvzBase()->MPtr<APvzStruct>(0x768)->MPtr<APvzStruct>(0x160)->MRef<int>(0x6c);
}

int initialVaseCount() {
    return AGetPvzBase()->MPtr<APvzStruct>(0x768)->MPtr<APvzStruct>(0x160)->MRef<int>(0xb0);
}

void getRowZombies(int row, std::vector<AZombie*>& pZombies) {
    // AAliveFilter<AZombie> zombieFilter;
    for (auto& zombie : aAliveZombieFilter) {
        if (zombie.Row() == row) {
            AZombie* pZombie = &zombie;
            pZombies.push_back(pZombie);
        }
    }
}

#endif
