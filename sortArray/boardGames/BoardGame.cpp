#include "BoardGame.h"
#include <iostream>
//Average Happiness calculation
float BoardGame::calculateAverageHappiness() {
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
    BoardGame::name = "25charString25charStringg";
    BoardGame::publisher = "25charString25charStringg";
    BoardGame::maxPlayers = 10;
    BoardGame::playTime = 480;
    BoardGame::difficultyLevel = 10;
    BoardGame::happinessFactor = 10;
    BoardGame::averageScore = 10;
}
//Constructor
BoardGame::BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor) {
    BoardGame::name = name;
    BoardGame::publisher = publisher;
    BoardGame::maxPlayers = maxPlayers;
    BoardGame::playTime = playTime;
    BoardGame::difficultyLevel = difficultyLevel;
    BoardGame::happinessFactor = happinessFactor;
    BoardGame::averageScore = calculateAverageHappiness();
}

//Operators
bool BoardGame::operator<(const BoardGame& other) const {
    return averageScore<other.averageScore;
}

bool BoardGame::operator>(const BoardGame &other) const {
    return averageScore>other.averageScore;
}

bool BoardGame::operator==(const BoardGame &other) const {
    return averageScore==other.averageScore;
}

ostream & operator<<(ostream &os, const BoardGame& obj) {
    os << "\n-'" << obj.name << "' by " << obj.publisher << " (" << obj.maxPlayers << "," << obj.playTime << "," << obj.difficultyLevel<< ","  << obj.happinessFactor << "): " << obj.averageScore << " points";
    return os;
}
