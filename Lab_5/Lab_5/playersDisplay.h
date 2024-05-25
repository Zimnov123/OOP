#ifndef PLAYERS_DISPLAY_H
#define PLAYERS_DISPLAY_H

#include <string>
#include "Player.h"
#include "player_di_container.h"

void displayAllPlayers(PlayerDIContainer& container, int playerCount);

void displayInfo(PlayerDIContainer& container, const string& playerName);

void sortAndDisplayPlayer(PlayerDIContainer& container, int& playerCount);

#endif
