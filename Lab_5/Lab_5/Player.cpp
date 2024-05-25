#include "Player.h"
#include <algorithm>
#include <fstream>

using namespace std;

Player::Player() {}

Player::Player(const string& n, int init, int hp, int maxHp, initializer_list<string> rn, initializer_list<int> mrc, initializer_list<int> ms, initializer_list<int> ss, initializer_list<int> res, int hitDice, int maxHitDice, string info)
    : name(n), initiative(init), health(hp), maxHealth(maxHp), hitDiceCount(hitDice), maxHitDiceCount(maxHitDice), information(info) {

    auto rnIter = rn.begin();
    for (int i = 0; i < 10 && rnIter != rn.end(); ++i, ++rnIter) {
        resourceName[i] = *rnIter;
    }

    auto mrcIter = mrc.begin();
    for (int i = 0; i < 10 && mrcIter != mrc.end(); ++i, ++mrcIter) {
        maxResourceCount[i] = *mrcIter;
    }

    auto msIter = ms.begin();
    for (int i = 0; i < 10 && msIter != ms.end(); ++i, ++msIter) {
        maxSpellSlots[i] = *msIter;
    }

    auto ssIter = ss.begin();
    for (int i = 0; i < 10 && ssIter != ss.end(); ++i, ++ssIter) {
        spellSlots[i] = *ssIter;
    }

    auto resIter = res.begin();
    for (int i = 0; i < 10 && resIter != res.end(); ++i, ++resIter) {
        resourcesArray[i] = *resIter;
    }
}

void Player::saveToFile(ofstream& file) const {
    file << name << " ";
    file << initiative << " ";
    file << health << " ";
    file << maxHealth << " ";
    for (int i = 0; i < 10; ++i) {
        file << resourceName[i] << " ";
    }
    for (int i = 0; i < 10; ++i) {
        file << maxResourceCount[i] << " ";
    }
    for (int i = 0; i < 10; ++i) {
        file << maxSpellSlots[i] << " ";
    }
    for (int i = 0; i < 10; ++i) {
        file << spellSlots[i] << " ";
    }
    for (int i = 0; i < 10; ++i) {
        file << resourcesArray[i] << " ";
    }
    file << hitDiceCount << " ";
    file << maxHitDiceCount << " ";
}

void Player::loadFromFile(ifstream& file) {
    file >> name;
    file >> initiative;
    file >> health;
    file >> maxHealth;
    for (int i = 0; i < 10; ++i) {
        file >> resourceName[i];
    }
    for (int i = 0; i < 10; ++i) {
        file >> maxResourceCount[i];
    }
    for (int i = 0; i < 10; ++i) {
        file >> maxSpellSlots[i];
    }
    for (int i = 0; i < 10; ++i) {
        file >> spellSlots[i];
    }
    for (int i = 0; i < 10; ++i) {
        file >> resourcesArray[i];
    }
    file >> hitDiceCount;
    file >> maxHitDiceCount;
}
