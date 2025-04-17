#ifndef BOARDGAMES_H
#define BOARDGAMES_H
#include <string>

using namespace std;

class BoardGame {
    public:
        string name;
        string publisher;
        int maxPlayers;
        int playTime;
        int difficultyLevel;
        int happinessFactor;
        int averageHappiness();
        BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor);
};
#endif