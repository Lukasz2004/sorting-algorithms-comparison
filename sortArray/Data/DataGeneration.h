#ifndef DATAGENERATION_H
#define DATAGENERATION_H
#include <cstdlib>
#include <string>

#include "../Array/FunctionalArray.h"

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
#endif