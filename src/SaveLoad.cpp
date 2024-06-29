#include "SaveLoad.h"

void saveGame(MyCharacter &Mine, Entity Crates[]) {
    std::ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        saveFile << Mine.getxpos() << " " << Mine.getypos() << " " << Mine.getLifeMCINT() << " " << Mine.getPointMCINT() << "\n";
        for (int i = 0; i < 8; i++) {
            saveFile << Crates[i].getXE() << " " << Crates[i].getYE() << "\n";
        }
        saveFile.close();
    }
}

bool loadGame(MyCharacter &Mine, Entity Crates[], SDL_Texture* MC, SDL_Texture* crates) {
    std::ifstream loadFile("savegame.txt");
    if (loadFile.is_open()) {
        int x, y, life, score;
        loadFile >> x >> y >> life >> score;
        Mine = MyCharacter(x, y, MC);
        Mine.setLife(life);
        Mine.setPoint(score);

        for (int i = 0; i < 8; i++) {
            loadFile >> x >> y;
            Crates[i] = Entity(x, y, crates);
        }
        loadFile.close();
        return true;
    }
    return false;
}
