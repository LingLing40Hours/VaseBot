#include <avz.h> // 包含本框架的头文件

void breakVase(int tile_x, int tile_y);
void breakAll();
int currentLevel();
bool isStable(int row);

ALogger<AMsgBox> logger;
ATickRunner tickRunner;
void AScript()
{
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    AConnect('Q', [] {
        breakVase(1, 9);
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

void breakVase(int tile_x, int tile_y)
{ // x rightwards from 1, y downwards from 1a
    ALeftClick(tile_x, tile_y);
}

void breakAll()
{
    for (int x = 3; x <= 9; ++x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(x, y);
        }
    }
}

int currentLevel() // int 0x6C, 0x160, 0x768, 0x6A9EC0
{
    return AGetPvzBase()->MPtr<APvzStruct>(0x768)->MPtr<APvzStruct>(0x160)->MRef<int>(0x6c);
}

bool isStable(int row)
{
    return true;
}