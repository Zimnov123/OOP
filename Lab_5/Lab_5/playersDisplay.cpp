#include <iostream>
#include <algorithm>
#include "playersDisplay.h"
#include "player_di_container.h"
#include "playersEdit.h"

using namespace std;

void displayInfo(PlayerDIContainer& container, const string& playerName) {
    Player* player = static_cast<Player*>(container.resolveDependency(playerName));
    if (player != nullptr) {
        cout << "Name: " << player->name << endl;
        cout << "Initiative: " << player->initiative << endl;
        cout << "Missing Health: " << player->health;
        if (player->maxHealth != 999) {
            cout << "/" << player->maxHealth;
        }
        cout << endl;
        if (player->maxSpellSlots[0] != 0) {
            cout << "Missing Spell Slots: ";
            for (int i = 0; i < 10; ++i) {
                if (player->maxSpellSlots[i] != 0)
                    cout << player->spellSlots[i] << "/" << player->maxSpellSlots[i] << " ";
            }
            cout << endl;
        }
        if (player->maxResourceCount[0] != 0) {
            for (int i = 0; i < 10; ++i) {
                if (player->resourceName[i] != "-") {
                    cout << player->resourceName[i];
                    if (i != 9 && player->resourceName[i + 1] != "-")
                        cout << "/";
                }
            }
            cout << ": ";
            for (int i = 0; i < 10; ++i) {
                if (player->maxResourceCount[i] != 0)
                    cout << player->resourcesArray[i] << "/" << player->maxResourceCount[i] << " ";
            }
            cout << endl;
        }
        if (player->maxHitDiceCount != 0)
            cout << "Hit Dice Count: " << player->hitDiceCount << "/" << player->maxHitDiceCount << endl;
        if (player->information != "-") {
            cout << "Additional Information : " << player->information << endl;
        }
        cout << "------------------------\n";
    }
    else {
        cout << "Player not found.\n";
    }
}

void displayAllPlayers(PlayerDIContainer& container, int playerCount) {
    for (int i = 0; i < playerCount; ++i) {
        string playerName = "player_" + to_string(i + 1);
        cout << "Player " << i + 1 << ":\n";
        displayInfo(container, playerName);
    }
}

void sortAndDisplayPlayer(PlayerDIContainer& container, int& playerCount) {
    Player** players = new Player * [playerCount];
    string* playerKeys = new string[playerCount];

    for (int i = 1; i <= playerCount; ++i) {
        string key = "player_" + to_string(i);
        players[i - 1] = static_cast<Player*>(container.resolveDependency(key));
        playerKeys[i - 1] = key;
    }

    sort(players, players + playerCount, [](Player* a, Player* b) {
        return a->initiative > b->initiative;
        });

    for (int i = 0; i < playerCount; ++i) {
        container.removeDependency(playerKeys[i]);
        string newKey = "player_" + to_string(i + 1);
        container.registerDependency(newKey, players[i]);
    }

    cout << "------------------------\n";
    for (int i = 0; i < playerCount; ++i) {
        cout << "Player " << i + 1 << ":\n";
        displayInfo(container, "player_" + to_string(i + 1));
    }

    delete[] players;
    delete[] playerKeys;
}


