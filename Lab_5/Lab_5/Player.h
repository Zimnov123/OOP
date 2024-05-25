#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <initializer_list>

struct Player {
    std::string name = "";
    int initiative = 0;
    int health = 0;
    int maxHealth = 999;
    std::string resourceName[10] = { "-" };
    int maxResourceCount[10] = { 0 };
    int maxSpellSlots[10] = { 0 };
    int maxHitDiceCount = 0;
    int spellSlots[10] = { 0 };
    int resourcesArray[10] = { 0 };
    int hitDiceCount = 0;
    std::string information = "-";

    Player();
    Player(const std::string& n, int init, int hp, int maxHp, std::initializer_list<std::string> rn, std::initializer_list<int> mrc, std::initializer_list<int> ms, std::initializer_list<int> ss, std::initializer_list<int> res, int hitDice, int maxHitDice, std::string info);

    void saveToFile(std::ofstream& file) const;

    void loadFromFile(std::ifstream& file);
};

#endif 
