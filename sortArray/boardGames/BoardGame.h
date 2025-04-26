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
        float averageHappiness() const;

        BoardGame();

        BoardGame(string name, string publisher, int maxPlayers, int playTime, int difficultyLevel, int happinessFactor);
        bool operator<(const BoardGame& other) const;
        bool operator>(const BoardGame& other) const;
        bool operator==(const BoardGame& other) const;
        friend ostream& operator<<(ostream& os,const BoardGame& obj);


};
#endif