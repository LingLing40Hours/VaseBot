//placeItem->IsDisappeared() indicates vase is broken
//placeItem.Row()/.Col() starts from 0
//APlaceItem *vase = &placeItem; works

//macro functions cannot call regular functions
//std::future<void> functions cannot use co_await
    //return std::async([]() {
    //});
    //return std::async([]() { return; });

/* passing parameters through ACoLaunch
if (x != 3 || y != 5) {
    ACoLaunch(std::bind(waitCS, MOUSE_CD));
    //ACoLaunch([] {return waitCS(MOUSE_CD);});
}*/

/* looping over seed packets
    AConnect('W', [] {
        int gx = LAWN_TILE_WIDTH, gy = 1;
        int itemTotal = AGetMainObject()->ItemTotal();
        auto itemArray = AGetMainObject()->ItemArray();
        for (int itemID=0; itemID < itemTotal; ++itemID) {
            auto &item = itemArray[itemID];

            if (item.Type() == 16) { //is seed packet
                int seedType = item.MRef<int>(0x68);

                if (seedType == ASNOW_PEA) { //is snow pea

                    //plant seed
                    ALeftClick(item.Abscissa(), item.Ordinate());
                    AClickGrid(gy, gx);
                    ++gy;
                    if (gy == LAWN_TILE_HEIGHT+1) {
                        --gx;
                        gy = 1;
                    }
                }
            }
        }
    });
*/

/* placeItem pointer testing
ACoroutine test() {
    //get pointer to top right vase
    APlaceItem *i = NULL;
    for (auto &placeItem : aAlivePlaceItemFilter) {
        if (placeItem.MRef<int>(0x8) == 7 && placeItem.Row() == 0 && placeItem.Col() == 8) {
            i = &placeItem;
        }
    }

    //break all vases
    for (int x = 9; x >= 3; --x) {
        for (int y = 1; y <= 5; ++y) {
            breakVase(y, x);
            co_await ANowDelayTime(MOUSE_CD);
        }
    }
    msgBoxLogger.Error("broke");

    //check if i->IsDisappeared() works
    if (i->IsDisappeared()) {
        msgBoxLogger.Error("disappeared");
    }
    else {
        msgBoxLogger.Error("still here");
    }
}
*/

/* tickRunner, zombie info
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
*/

//non-functional music controls; see setMusicVolume in output.h
//double *pMusicVolume = reinterpret_cast<double*>(0x6a9ec0 + 0xd0);
//volatile double &musicVolume = AMPtr<APvzStruct>(0x6a9ec0)->MRef<double>(0xd0); //doesn't work unless set manually
//volatile bool &musicPaused = AMPtr<APvzStruct>(0x6a9ec0)->MPtr<APvzStruct>(0x83c)->MRef<bool>(0x40);

    //musicVolume = 0; //-std::numeric_limits<double>::infinity();
    //musicPaused = true;

    //void (*BASS_Stop)() = reinterpret_cast<void(*)()>(reinterpret_cast<int>(0x6a9ff0) + 0x1c);
    //BASS_Stop();

    //void (*setMusicVolume)(double) = reinterpret_cast<void(*)(double)>(0x554d70);
    //setMusicVolume(0);

/* find house_x0
    tickRunner.Start([] {
        double minX = std::numeric_limits<double>::infinity();
        for (auto &zombie : aAliveZombieFilter) {
            if (zombie.Abscissa() < minX) {
                minX = zombie.Abscissa();
            }
        }
        if (minX < -99)
            msgBoxLogger.Error(std::to_string(minX));
    });
*/