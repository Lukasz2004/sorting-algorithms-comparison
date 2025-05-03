#include "BoardGame.h"
#include <iostream>
//Average Happiness calculation
float BoardGame::averageHappiness() const {
    float avgHappiness = happinessFactor*maxPlayers;
    avgHappiness /= difficultyLevel;
    avgHappiness /= playTime;
    if (name.find("Cat")!=-1) {
        avgHappiness*=3;
    }
    if (name.find("Dog")!=-1) {
        avgHappiness/=3;
    }
    return avgHappiness;
}

//Default constructor required for memory allocation
BoardGame::BoardGame() {
    BoardGame::name = new char[25];
    BoardGame::publisher = new char[25];
    BoardGame::maxPlayers = 10;
    BoardGame::playTime = 480;
    BoardGame::difficultyLevel = 10;
    BoardGame::happinessFactor = 10;
}
//Constructor
BoardGame::BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor) {
    BoardGame::name = name;
    BoardGame::publisher = publisher;
    BoardGame::maxPlayers = maxPlayers;
    BoardGame::playTime = playTime;
    BoardGame::difficultyLevel = difficultyLevel;
    BoardGame::happinessFactor = happinessFactor;
}

//Operators
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
