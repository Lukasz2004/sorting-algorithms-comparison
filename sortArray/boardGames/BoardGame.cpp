//
// Created by lukas on 10.04.2025.
//

#include "BoardGame.h"
#include <iostream>
float BoardGame::averageHappiness() const {
    float happinessFactor = BoardGame::happinessFactor*BoardGame::maxPlayers;
    happinessFactor /= BoardGame::difficultyLevel;
    happinessFactor /= BoardGame::playTime;
    if (BoardGame::name.find("Cat")!=-1) {
        happinessFactor*=3;
    }
    if (BoardGame::name.find("Dog")!=-1) {
        happinessFactor/=3;
    }
    return happinessFactor;
}
BoardGame::BoardGame() {
    BoardGame::name = new char[25];
    BoardGame::publisher = new char[25];
    BoardGame::maxPlayers = 10;
    BoardGame::playTime = 480;
    BoardGame::difficultyLevel = 10;
    BoardGame::happinessFactor = 10;
}
BoardGame::BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor) {
    BoardGame::name = name;
    BoardGame::publisher = publisher;
    BoardGame::maxPlayers = maxPlayers;
    BoardGame::playTime = playTime;
    BoardGame::difficultyLevel = difficultyLevel;
    BoardGame::happinessFactor = happinessFactor;
}

bool BoardGame::operator<(const BoardGame& other) const {
    return averageHappiness()<other.averageHappiness();
}

bool BoardGame::operator>(const BoardGame &other) const {
    return averageHappiness()>other.averageHappiness();
}

bool BoardGame::operator==(const BoardGame &other) const {
    return averageHappiness()==other.averageHappiness();
}

ostream & operator<<(ostream &os, const BoardGame& obj) {
    os << "\n-'" << obj.name << "' by " << obj.publisher << " (" << obj.maxPlayers << "," << obj.playTime << "," << obj.difficultyLevel<< ","  << obj.happinessFactor << "): " << obj.averageHappiness() << " points";
    return os;
}
