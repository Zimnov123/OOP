#ifndef SAVE_AND_LOAD_H
#define SAVE_AND_LOAD_H

#include "Player.h"
#include <fstream>
#include "player_di_container.h" 

void savePlayersToFile(PlayerDIContainer& container, int playerCount);

int loadPlayersFromFile(PlayerDIContainer& container);

#endif 
