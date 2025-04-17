#ifndef DATAGENERATION_H
#define DATAGENERATION_H
#include <cstdlib>
#include <string>

#include "../array/FunctionalArray.h"

using namespace std;
template <typename dataType> class DataGeneration {
    public:
        static FunctionalArray<dataType> generateArray(int size);
};

template <> FunctionalArray<int> DataGeneration<int>::generateArray(int size) {
    FunctionalArray<int> returnArray = FunctionalArray<int>(size);
    for (int i=0; i<size; i++) {
        returnArray.setElement(i,  rand());
    }
    return returnArray;
}
template <> FunctionalArray<float> DataGeneration<float>::generateArray(int size) {
    FunctionalArray<float> returnArray = FunctionalArray<float>(size);
    for (int i=0; i<size; i++) {
        float value1 = rand();
        float value2 = rand();
        returnArray.setElement(i,value1/value2);
    }
    return returnArray;
}
template <> FunctionalArray<string> DataGeneration<string>::generateArray(int size) {
    FunctionalArray<char> keysArray = FunctionalArray<char>(35);
    FunctionalArray<string> returnArray = FunctionalArray<string>(size);
    for (int i=0; i<=9; i++) {
        keysArray.setElement(i, (char) '0' + i);
    }
    for (int i=0; i<24; i++) {
        keysArray.setElement(i+10, (char) 'a' + i);
    }
    for (int i=0; i<size; i++) {
        int stringLength = rand()%20 + 1;
        string tempString = "";
        for (int ii=0; ii<stringLength; ii++) {
            tempString += keysArray.getElement(rand()%35);
        }
        returnArray.setElement(i,tempString);
    }
    return returnArray;
}
template <> FunctionalArray<BoardGame> DataGeneration<BoardGame>::generateArray(int size) {
    FunctionalArray<string> nameKeysArray = FunctionalArray<string>(10);
    nameKeysArray.setElement(0,"Return");
    nameKeysArray.setElement(1,"Of");
    nameKeysArray.setElement(2,"The");
    nameKeysArray.setElement(3,"Cat");
    nameKeysArray.setElement(4,"Revenge");
    nameKeysArray.setElement(5,"Dragon");
    nameKeysArray.setElement(6,"Castle");
    nameKeysArray.setElement(7,"A");
    nameKeysArray.setElement(8,"Cow");
    nameKeysArray.setElement(9,"Epic");

    FunctionalArray<BoardGame> returnArray = FunctionalArray<BoardGame>(size);
    for (int i=0; i<size; i++) {
        int stringLength = rand()%3+3;
        string tempName = "";
        for (int ii=0; ii<stringLength; ii++) {
            tempName += nameKeysArray.getElement(rand()%10);
        }
        int tempMaxPlayers = 1;
        int tempPlayTime = 1;
        int tempDifficultyLevel = 1;
        int tempHappinessFactor = 1;
        BoardGame tempBoardGame(tempName, tempName, tempMaxPlayers, tempPlayTime, tempDifficultyLevel, tempHappinessFactor);
        returnArray.setElement(i,tempBoardGame);
    }
    return returnArray;
}
#endif