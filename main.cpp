#include <avz.h> // 包含本框架的头文件

// 本框架的入口函数是 `void AScript()`
void AScript()
{
    // 注意此条代码需要到选卡界面或者战斗界面才能看到运行效果
    aPainter.Draw(AText("Hello AsmVsZombies", 400, 300), 500);

    tickRunner {
        
    }
}

void breakVase(int tile_x, int tile_y) { //x rightwards from 1, y downwards from 1

}

void breakAll() {
    for (int x=3; x<=9; ++x) {
        for (int y=1; y<=5; ++y) {
            breakVase(x, y);
        }
    }
}

int currentLevel() {

}