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
        int gx = LAWN_WIDTH, gy = 1;
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
                    if (gy == LAWN_HEIGHT+1) {
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