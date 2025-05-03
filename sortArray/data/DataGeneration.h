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

//Specialization for int
template <> FunctionalArray<int> DataGeneration<int>::generateArray(int size) {
    FunctionalArray<int> returnArray = FunctionalArray<int>(size);
    for (int i=0; i<size; i++) {
        int temp = rand();
        //Chance for negative number
        if (rand()%2==0) {
            temp*=-1;
        }
        returnArray.setElement(i, temp);
    }
    return returnArray;
}
//Specialization for float
template <> FunctionalArray<float> DataGeneration<float>::generateArray(int size) {
    FunctionalArray<float> returnArray = FunctionalArray<float>(size);
    for (int i=0; i<size; i++) {
        float value1 = rand();
        //Chance for negative number
        if (rand()%2==0) {
            value1*=-1;
        }
        float value2 = rand();
        //Chance for negative number
        if (rand()%2==0) {
            value2*=-1;
        }
        returnArray.setElement(i,value1/value2);
    }
    return returnArray;
}
//Specialization for string
template <> FunctionalArray<string> DataGeneration<string>::generateArray(int size) {
    //Preparing available keys
    FunctionalArray<char> keysArray = FunctionalArray<char>(35);
    FunctionalArray<string> returnArray = FunctionalArray<string>(size);
    for (int i=0; i<=9; i++) {
        keysArray.setElement(i, (char) '0' + i);
    }
    for (int i=0; i<24; i++) {
        keysArray.setElement(i+10, (char) 'a' + i);
    }


    for (int i=0; i<size; i++) {
        int stringLength = rand()%24 + 1; //Length between 1 and 25
        string tempString = "";
        for (int ii=0; ii<stringLength; ii++) {
            tempString += keysArray.getElement(rand()%35); //Picks key from keys at random and adds to tempString
        }
        returnArray.setElement(i,tempString);
    }
    return returnArray;
}
//Specialization for BoardGames
template <> FunctionalArray<BoardGame> DataGeneration<BoardGame>::generateArray(int size) {
    //Preparing available keys
    FunctionalArray<string> nameKeysArray = FunctionalArray<string>(17);
    nameKeysArray.setElement(0,"Return");
    nameKeysArray.setElement(1,"Social");
    nameKeysArray.setElement(2,"Journey");
    nameKeysArray.setElement(3,"Cat");
    nameKeysArray.setElement(4,"Revenge");
    nameKeysArray.setElement(5,"Dragon");
    nameKeysArray.setElement(6,"Castle");
    nameKeysArray.setElement(7,"Battle");
    nameKeysArray.setElement(8,"Cow");
    nameKeysArray.setElement(9,"Epic");
    nameKeysArray.setElement(10,"Magic");
    nameKeysArray.setElement(11,"Warrior");
    nameKeysArray.setElement(12,"Impossible");
    nameKeysArray.setElement(13,"Quest");
    nameKeysArray.setElement(14,"Taco");
    nameKeysArray.setElement(15,"Pizza");
    nameKeysArray.setElement(16,"Dog");

    FunctionalArray<string> publisherArray = FunctionalArray<string>(3);
    publisherArray.setElement(0," Corp.");
    publisherArray.setElement(1," Ent.");
    publisherArray.setElement(2,"");

    FunctionalArray<BoardGame> returnArray = FunctionalArray<BoardGame>(size);
    for (int i=0; i<size; i++) {
        int stringLength = rand()%3+3; //Title between 3 and 5 words
        string tempName = "";
        for (int ii=0; ii<stringLength; ii++) {
            if (ii!=0) tempName += " ";
            tempName += nameKeysArray.getElement(rand()%(nameKeysArray.size-1)); //Picks key from keys at random and adds to tempName
        }
        string tempPublisher = "";
        stringLength = rand()%2+2; //Publisher name contains between 2 and 4 cut words (45%)
        for (int ii=0; ii<stringLength; ii++) {
            string tempkey = nameKeysArray.getElement(rand()%(nameKeysArray.size-1));
            if (ii!=0) {
                tempkey[0]=tempkey[0]-('A'-'a');
            }
            tempPublisher += tempkey.substr(0,tempkey.size()*0.45); //Picks key from keys at random and adds 45% to tempPublisher
        }
        tempPublisher += publisherArray.getElement(rand()%(publisherArray.size-1));
        int tempMaxPlayers = rand()%9+1; //MaxPlayers between 1 and 10
        int tempPlayTime = rand()%475+5; //PlayTime between 5 and 480
        int tempDifficultyLevel = rand()%9+1; //DifficultyLevel between 1 and 10
        int tempHappinessFactor = rand()%9+1; //HappinessFactor between 1 and 10
        //Create the BoardGame
        BoardGame tempBoardGame(tempName, tempPublisher, tempMaxPlayers, tempPlayTime, tempDifficultyLevel, tempHappinessFactor);
        //Add to array
        returnArray.setElement(i,tempBoardGame);
    }
    return returnArray;
}

#endif