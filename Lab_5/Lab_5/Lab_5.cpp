#include <iostream>
#include <windows.h> 
#include "Player.h"
#include "saveAndLoad.h"
#include <algorithm>
#include "playersEdit.h"
#include "player_di_container.h"
#include "playersDisplay.h"

using namespace std;

const int MAX_PLAYERS = 100;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Player* players = new Player[MAX_PLAYERS];
    int playerCount = 0;

    PlayerDIContainer container;

    playerCount = loadPlayersFromFile(container);

    while (true) {
        cout << "1. Add Player\n";
        cout << "2. Display Players by Initiative\n";
        cout << "3. Edit Player\n";
        cout << "4. Edit Max Value\n";
        cout << "5. Sleep\n";
        cout << "6. Area Dmg\n";
        cout << "7. Delete Player\n";
        cout << "8. Save Players to File\n";
        cout << "9. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        choice = checkCorrect();
        cout << "\n";

        switch (choice) {
        case 1: {
            addPlayerOrBot(players, playerCount, MAX_PLAYERS, container);
            break;
        }

        case 2: {
            sortAndDisplayPlayer(container, playerCount);
            break;
        }
        case 3: {
            chooseToEditPlayer(choice, container, playerCount);
            break;
        }

        case 4: {
            choosePlayerToChangeMax(choice, container);
            break;
        }

        case 5: {
            cout << "How long your sleep?" << endl;
            cout << "1. Short" << endl;
            cout << "2. Long" << endl;
            int sizeOfSleep;
            sizeOfSleep = checkCorrect();
            resetResourcesAndSpellSlots(container, sizeOfSleep, playerCount);
            break;
        }
        case 6: {
            areaDMG(container, playerCount);
            break;
        }
        case 7: {
            string playerName;
            cout << "Enter the name of the player to delete: ";
            cin >> playerName;
            deletePlayer(container, playerCount, playerName);
            break;
        }
        case 8: {
            savePlayersToFile(container, playerCount);
            break;
        }
        case 9:
            savePlayersToFile(container, playerCount);
            delete[] players;
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}