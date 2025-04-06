#include <fstream>
#include <stdlib.h>
#include <typeinfo>

#include "FunctionalArray.h"

template <typename dataType> class FileLoader {
public:
    static FunctionalArray<dataType> loadFile(string filename) {
        ifstream file;
        file.open(filename.c_str());
        string tempInput;
        getline(file, tempInput);
        int numberOfLines = atoi(tempInput.c_str());
        FunctionalArray<dataType> tempArray = FunctionalArray<dataType>(numberOfLines);
        for (int i = 0; i < numberOfLines; i++) {
            getline(file, tempInput);
            tempArray.setElement(i, convertString(tempInput));
        }
        return tempArray;
    }
    static dataType convertString(string input){};
};

template <> int FileLoader<int>::convertString(string input) {
    return atoi(input.c_str());
}
template <> string FileLoader<string>::convertString(string input) {
    return input;
}

