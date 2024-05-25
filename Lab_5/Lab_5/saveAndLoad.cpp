#include "saveAndLoad.h"

using namespace std;

void savePlayersToFile(PlayerDIContainer& container, int playerCount) {
    ofstream outFile("players.txt");
    if (!outFile) {
        return;
    }

    outFile << playerCount << endl;

    for (int i = 1; i <= playerCount; ++i) {
        Player* player = static_cast<Player*>(container.resolveDependency("player_" + to_string(i)));
        if (player != nullptr) {
            player->saveToFile(outFile);
            outFile << endl;
        }
    }

    outFile.close();
}

int loadPlayersFromFile(PlayerDIContainer& container) {
    ifstream inFile("players.txt");
    if (!inFile) {
        return 0;
    }

    int playerCount;
    inFile >> playerCount;

    for (int i = 1; i <= playerCount; ++i) {
        Player* player = new Player();
        player->loadFromFile(inFile);
        container.registerDependency("player_" + to_string(i), player);
    }

    inFile.close();
    return playerCount;
}
