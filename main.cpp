#include "constants.h"
#include "prototypes.h"
#include <avz.h> // 包含本框架的头文件
#include <vector>

int vaseCounter = -1;
int* pVaseCounter = &vaseCounter;

void AScript()
{
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    // aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    AConnect('Q', [] {
        breakAll(pVaseCounter);
        // logger.Info("current level: #", currentLevel());
    });

    AConnect('W', [] {
        ACard(AREPEATER, 1, 1);
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

        int y = 0;
        for (auto& zombie : aAliveZombieFilter) {
            if (zombie.Type() == AZOMBIE) {
                aPainter.Draw(AText("A Regular Zombie with speed " + std::to_string(zombie.Speed()), 200, y), 1);
                y += 20;
            }
        }
        aPainter.Draw(AText("vaseCounter: " + std::to_string(vaseCounter), 50, 10), 1);
    });
}
