#include <avz.h> // 包含本框架的头文件

void breakVase(int tile_x, int tile_y);
void breakAll();
int currentLevel();
bool isStable(int row);
vector<AZombie> rowZombies(int row);

ALogger<AMsgBox> logger;
ATickRunner tickRunner;
void AScript()
{
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    AConnect('Q', [] {
<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream
        breakVase(1, 9);
=======
        breakVase(9, 1);
>>>>>>> Stashed changes
=======
        breakVase(9, 1);
>>>>>>> Stashed changes
=======
        breakVase(9, 1);
>>>>>>> Stashed changes
        // logger.Info("current level: #", currentLevel());
    });

    tickRunner.Start([] {
        AAliveFilter<AZombie> zombieFilter;
        int y = 0;
        for (auto&& zombie : zombieFilter) {
            if (zombie.Type() == AZOMBIE) {
                aPainter.Draw(AText("A Regular Zombie with speed " + std::to_string(zombie.Speed()), 200, y), 1);
                y += 20;
            }
        }
    });
}

void breakVase(int tile_y, int tile_x)
{ // x rightwards from 1, y downwards from 1a
    AClickGrid(tile_y, tile_x);
}

void breakAll()
{
    for (int x = 9; x >= 3; --x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(y, x);
        }
    }
}

int currentLevel() // int 0x6C, 0x160, 0x768, 0x6A9EC0
{
    return AGetPvzBase()->MPtr<APvzStruct>(0x768)->MPtr<APvzStruct>(0x160)->MRef<int>(0x6c);
}

// recurse upon zombie death, plant death, zombie reach plant
// end upon zombie reach house
bool isStable(int row,
    vector<AZombie>& zombies, double* zombieAbscissas, int zombieCount,
    vector<APlant>& plants, double* plantHealths, int plantCount)
{
    vector<AZombie> zombies = rowZombies(row);
    for (AZombie zombie : zombies) {
        if (zombie.AttackAbscissa() > plant_left && zombie.AttackAbscissa() < plant_right) {
            // plant under attack
        }
    }
    return true;
}

vector<AZombie>& rowZombies(int row)
{
    vector<AZombie> zombies;
    AAliveFilter<AZombie> zombieFilter;
    for (auto&& zombie : zombieFilter) {
        if (zombie.Row() == row) {
            zombies.push_back(zombie);
        }
    }
    return zombies;
}