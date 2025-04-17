//
// Created by lukas on 10.04.2025.
//

#include "BoardGame.h"
int BoardGame::averageHappiness() {
    int happinessFactor = BoardGame::happinessFactor/BoardGame::maxPlayers;
    happinessFactor /= BoardGame::difficultyLevel;
    if (BoardGame::name.find("cat")!=-1) {
        happinessFactor*=3;
    }
    return happinessFactor;
}
BoardGame::BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor) {
    BoardGame::name = name;
    BoardGame::publisher = publisher;
    BoardGame::maxPlayers = maxPlayers;
    BoardGame::playTime = playTime;
    BoardGame::difficultyLevel = difficultyLevel;
    BoardGame::happinessFactor = happinessFactor;
}

