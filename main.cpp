#include <avz.h>    // 包含本框架的头文件
#include <vector>
#include "globals.h"
#include "computation.h"
#include "input.h"
#include "output.h"

//int vaseCounter = -1;
//int* pVaseCounter = &vaseCounter;

void AScript() {
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    // aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    AConnect('Q', breakAll);

    AConnect('W', [] {
        ACard(AREPEATER, 1, 1);
    });

    tickRunner.Start([] {
        // debug
        int y = 0;
        for (auto& zombie : aAliveZombieFilter) {
            if (zombie.Type() == AZOMBIE) {
                aPainter.Draw(AText("A Regular Zombie with speed " + std::to_string(zombie.Speed()), 200, y), 1);
                y += 20;
            }
        }
    });
}
