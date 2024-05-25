#include "playersEdit.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "playersDisplay.h"
#include "player_di_container.h"

using namespace std;

int checkCorrect() {
    int number;
    while (true) {
        cin >> number;

        if (cin.fail()) {
            cout << "Please enter a correct number!" << endl;
            cin.clear();
            cin.ignore(10000000000, '\n');
        }
        else {
            break;
        }
    }
    return number;
}

string findPlayerIdByName(PlayerDIContainer& container, const string& playerName, int playerCount) {
    for (int i = 1; i <= playerCount; ++i) {
        Player* player = static_cast<Player*>(container.resolveDependency("player_" + to_string(i)));
        if (player != nullptr && player->name == playerName) {
            return to_string(i);
        }
    }
    return "- 1";
}

void editMaxValues(PlayerDIContainer& container, const string& playerName) {
    Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerName));
    if (player != nullptr) {
        int choice;
        cout << "Which max value do you want to edit?\n";
        cout << "1. Max Health\n";
        cout << "2. Max Spell Slots\n";
        cout << "3. Max Resources\n";
        cout << "4. Name Resources\n";
        cout << "5. Max Hit Dice Count\n";
        cout << "Enter your choice: ";
        choice = checkCorrect();

        switch (choice) {
        case 1: {
            int newMaxHealth;
            cout << "Enter new max health: ";
            newMaxHealth = checkCorrect();
            player->maxHealth = newMaxHealth;
            break;
        }
        case 2: {
            int newMaxSpellSlots;
            int temp5;
            cout << "Enter the index of the spell slot to edit max (1-10): ";
            temp5 = checkCorrect();
            cout << "Enter new max spell slot: ";
            newMaxSpellSlots = checkCorrect();
            player->maxSpellSlots[temp5 - 1] = newMaxSpellSlots;
            break;
        }
        case 3: {
            int newMaxResources;
            int temp5;
            cout << "Enter the index of the resource to edit max (1-10): ";
            temp5 = checkCorrect();
            cout << "Enter new max resource count: ";
            newMaxResources = checkCorrect();
            player->maxResourceCount[temp5 - 1] = newMaxResources;
            break;
        }
        case 4: {
            string resourceNames[10];
            int choice;
            char temp = 11;
            cout << "Do you want to add a new resource name or change? (1 for add, 2 for change all): ";
            choice = checkCorrect();
            if (choice == 1) {
                for (int i = 0; i < 10; i++) {
                    if (player->resourceName[i] == "-") {
                        temp = i;
                        break;
                    }
                }
                if (temp != 11) {
                    cout << "Enter new resource name: ";
                    cin >> resourceNames[temp];
                    player->resourceName[temp] = resourceNames[temp];
                }
                else {
                    cout << "Maximum of recources!" << endl;
                }
            }
            else if (choice == 2) {
                cout << "Enter the name of the new resources: ";
                for (int i = 0; i < 10; ++i) {
                    cin >> resourceNames[i];
                    player->resourceName[i] = resourceNames[i];
                    if (resourceNames[i] == "-") {
                        for (int j = i; j < 10; j++) {
                            resourceNames[j] = "-";
                            player->resourceName[j] = resourceNames[j];
                        }
                        break;
                    }
                }
            }
            else {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
            break;
        }
        case 5: {
            int newMaxHitDice;
            cout << "Enter new max hit dice count: ";
            newMaxHitDice = checkCorrect();
            player->maxHitDiceCount = newMaxHitDice;
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    else {
        cout << "Player not found.\n";
    }
}

void deletePlayer(PlayerDIContainer& container, int& playerCount, const string& playerName) {
    string playerId = findPlayerIdByName(container, playerName, playerCount);
    if (playerId != "-1") {
        container.removeDependency("player_" + playerId);
        cout << "Player " << playerName << " deleted successfully.\n";

        int deletedIndex = stoi(playerId) - 1;
        for (int i = deletedIndex; i < playerCount - 1; ++i) {
            Player* player = static_cast<Player*>(container.resolveDependency("player_" + to_string(i + 2)));
            if (player != nullptr) {
                container.removeDependency("player_" + to_string(i + 2));
                container.registerDependency("player_" + to_string(i + 1), player);
            }
        }

        --playerCount;
    }
    else {
        cout << "Player with name " << playerName << " not found.\n";
    }
}


void editPlayerField(PlayerDIContainer& container, const string& playerName) {
    Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerName));
    if (player != nullptr) {
        cout << "Select field to edit:\n";
        cout << "1. Name\n";
        cout << "2. Initiative\n";
        cout << "3. Health\n";
        cout << "4. Spell Slots\n";
        cout << "5. Resources\n";
        cout << "6. Hit Dice Count\n";
        cout << "7. Additional information\n";

        int fieldChoice;
        cout << "Enter your choice: ";
        cin >> fieldChoice;

        string temp;
        switch (fieldChoice) {
        case 1:
            cout << "Enter new player name: ";
            cin >> player->name;
            break;
        case 2:
            cout << "Enter new player initiative: ";
            cin >> player->initiative;
            break;
        case 3:
            cout << "Enter new player health: ";
            cin >> player->health;
            break;
        case 4:
            cout << "Select spell slot to edit (1-10): ";
            int spellIndex;
            cin >> spellIndex;
            if (spellIndex >= 1 && spellIndex <= 10) {
                cout << "Enter new value for spell slot " << spellIndex << ": ";
                cin >> player->spellSlots[spellIndex - 1];
            }
            else {
                cout << "Invalid spell slot index.\n";
            }
            break;
        case 5:
            cout << "Select resource to edit (1-10): ";
            int resourceIndex;
            cin >> resourceIndex;
            if (resourceIndex >= 1 && resourceIndex <= 10) {
                cout << "Enter new value for resource " << resourceIndex << ": ";
                cin >> player->resourcesArray[resourceIndex - 1];
            }
            else {
                cout << "Invalid resource index.\n";
            }
            break;
        case 6:
            cout << "Enter new hit dice count: ";
            cin >> player->hitDiceCount;
            break;
        case 7:
            cout << "Enter information: ";
            cin >> player->information;
            break;
        default:
            cout << "Invalid choice. No fields were edited.\n";
            break;
        }
    }
    else {
        cout << "Player not found.\n";
    }
}

void resetResourcesAndSpellSlots(PlayerDIContainer& container, int sizeOfSleep, int count) {
    for (int i = 0; i < count; ++i) {
        Player* player = static_cast<Player*>(container.resolveDependency("player_" + to_string(i + 1)));
        if (player != nullptr) {
            fill(begin(player->spellSlots), end(player->spellSlots), 0);
            fill(begin(player->resourcesArray), end(player->resourcesArray), 0);

            if (sizeOfSleep == 2) {
                player->health = 0;
                player->hitDiceCount = player->maxHitDiceCount;
            }
        }
    }
}

void editPlayerInitiative(PlayerDIContainer& container, const string& playerName, int count) {
    Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerName));
    if (player != nullptr) {
        if (player->information != "-") {
            player->information = "Priority: " + to_string(count) + ". " + player->information;
        }
        else {
            player->information = "Priority: " + to_string(count);
        }
    }
    else {
        cout << "Player not found." << endl;
    }
}

void addPlayerOrBot(Player players[], int& playerCount, int max, PlayerDIContainer& container) {
    if (playerCount >= max) {
        cout << "Maximum number of players reached.\n";
    }

    cout << "What is your choice?" << endl << "1. Add a mob" << endl << "2. Add a player" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        string name;
        int initiative;
        cout << "Enter mob name: ";
        cin >> name;

        cout << "Enter mob initiative: ";
        cin >> initiative;

        Player* player = new Player(name, initiative, 0, 999, { "-", "-", "-", "-", "-", "-", "-", "-", "-", "-" },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            0, 0, "-");
        container.registerDependency("player_" + to_string(playerCount+1), player);
        players[playerCount] = *player;
        ++playerCount;
    }
    else if (choice == 2) {
        string name;
        int maxHealth, hitDice;
        string resourceName[10];
        int maxResourceCount[10];
        int maxSpell[10];

        cout << "Enter player name: ";
        cin >> name;

        cout << "Enter player max health: ";
        cin >> maxHealth;

        cout << "Enter player resource names (10 values, type '-' to stop): ";
        for (int i = 0; i < 10; ++i) {
            cin >> resourceName[i];
            if (resourceName[i] == "-") {
                for (int j = i; j < 10; ++j) {
                    resourceName[j] = "-";
                }
                break;
            }
        }

        cout << "Enter player max resource count (10 values, type '0' to stop): ";
        for (int i = 0; i < 10; ++i) {
            cin >> maxResourceCount[i];
            if (maxResourceCount[i] == 0) {
                for (int j = i; j < 10; ++j) {
                    maxResourceCount[j] = 0;
                }
                break;
            }
        }

        cout << "Enter player max spell slots (10 values, type '0' to stop): ";
        for (int i = 0; i < 10; ++i) {
            cin >> maxSpell[i];
            if (maxSpell[i] == 0) {
                for (int j = i; j < 10; ++j) {
                    maxSpell[j] = 0;
                }
                break;
            }
        }

        cout << "Enter max hit dice count: ";
        cin >> hitDice;

        Player* player = new Player(name, 0, 0, maxHealth, { resourceName[0], resourceName[1], resourceName[2], resourceName[3], resourceName[4], resourceName[5], resourceName[6], resourceName[7], resourceName[8], resourceName[9] },
            { maxResourceCount[0], maxResourceCount[1], maxResourceCount[2], maxResourceCount[3], maxResourceCount[4], maxResourceCount[5], maxResourceCount[6], maxResourceCount[7], maxResourceCount[8], maxResourceCount[9] },
            { maxSpell[0], maxSpell[1], maxSpell[2], maxSpell[3], maxSpell[4], maxSpell[5], maxSpell[6], maxSpell[7], maxSpell[8], maxSpell[9] },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            hitDice, hitDice, "-");
        container.registerDependency("player_" + to_string(playerCount+1), player);
        players[playerCount] = *player;
        ++playerCount;
    }
    else {
        cout << "Wrong choice" << endl;
    }
}

void chooseToEditPlayer(int choice, PlayerDIContainer& container, int playerCount) {
    int playerIndex;
    string playerName;
    cout << "What is your choice?" << endl << "1. Edit player by name" << endl << "2. Edit player by index" << endl;
    choice = checkCorrect();
    if (choice == 1) {
        cout << "Enter the name of the player to edit: ";
        cin >> playerName;
        string playerId = findPlayerIdByName(container, playerName, playerCount);
        editPlayerField(container, playerId);
        cout << "Player " << playerName << " edited successfully.\n";
    }
    else if (choice == 2) {
        cout << "Enter the index of the player to edit: ";
        playerIndex = checkCorrect();

        string playerIndexStr = to_string(playerIndex);
        Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerIndexStr));

        if (player != nullptr) {
            cout << "Editing player " << playerIndex << ":\n";
            editPlayerField(container, player->name);
            cout << "Player " << playerIndex << " edited successfully.\n";
        }
        else {
            cout << "Invalid player index.\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void choosePlayerToChangeMax(int choice, PlayerDIContainer& container) {
    int playerIndex;
    string playerName;
    cout << "What is your choice?" << endl << "1. Edit player by name" << endl << "2. Edit player by index" << endl;
    choice = checkCorrect();
    if (choice == 1) {
        cout << "Enter the name of the player to edit: ";
        cin >> playerName;
        editMaxValues(container, playerName);
        cout << "Player " << playerName << " edited successfully.\n";
    }
    else if (choice == 2) {
        cout << "Enter the index of the player to edit: ";
        playerIndex = checkCorrect();

        string playerIndexStr = to_string(playerIndex);
        Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerIndexStr));

        if (player != nullptr) {
            cout << "Editing player " << playerIndex << ":\n";
            editPlayerField(container, player->name);
            cout << "Player " << playerIndex << " edited successfully.\n";
        }
        else {
            cout << "Invalid player index.\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void areaDMG(PlayerDIContainer& container, int& playerCount) {
    int areaDmg;
    cout << "Enter area dmg: ";
    cin >> areaDmg;

    string playerName;
    cout << "Enter players who get full dmg (for end enter 0):" << endl;
    while (cin >> playerName && playerName != "0") {
        string playerId = findPlayerIdByName(container, playerName, playerCount);
        if (playerId != "- 1") {
            Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerId));
            if (player != nullptr) {
                player->health += areaDmg;
            }
        }
        else {
            cout << "Player " << playerName << " not found." << endl;
        }
    }

    if (areaDmg % 2 == 1) {
        areaDmg -= 1;
    }
    areaDmg /= 2;

    cout << "Enter players who get half dmg (for end enter 0):" << endl;
    while (cin >> playerName && playerName != "0") {
        string playerId = findPlayerIdByName(container, playerName, playerCount);
        if (playerId != "-1") {
            Player* player = static_cast<Player*>(container.resolveDependency("player_" + playerId));
            if (player != nullptr) {
                player->health += areaDmg;
            }
        }
        else {
            cout << "Player " << playerName << " not found." << endl;
        }
    }
}
