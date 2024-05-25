#ifndef PLAYERSEDIT_H
#define PLAYERSEDIT_H

#include "Player.h"
#include "player_di_container.h"

void editMaxValues(PlayerDIContainer& container, const string& playerName);
void deletePlayer(PlayerDIContainer& container, int& playerCount, const string& playerName);
void editPlayerField(const PlayerDIContainer& container, const string& playerName);
void editPlayerInitiative(PlayerDIContainer& container, const string& playerName, int count);
void resetResourcesAndSpellSlots(PlayerDIContainer& container, int sizeOfSleep, int count);
void addPlayerOrBot(Player players[], int& playerCount, int max, PlayerDIContainer& container);
void chooseToEditPlayer(int choice, PlayerDIContainer& container, int playerCount);
void choosePlayerToChangeMax(int choice, PlayerDIContainer& container);
void areaDMG(PlayerDIContainer& container, int& playerCount);
int checkCorrect();

#endif 
