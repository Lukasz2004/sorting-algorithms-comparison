#include <fstream>
#include <cstdlib>

#include "FunctionalArray.h"

template <typename dataType> class FileOperations {
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
        file.close();
        return tempArray;
    }
    static dataType convertString(string input){};
    static void saveFile(Array<dataType> *array, string fileName) {
        ofstream file;
        file.open(fileName.c_str());
        file << array->size << endl;
        for (int i = 0; i < array->size; i++) {
            file << array->getElement(i) << endl;
        }
        file.close();
        return;
    }
};

template <> int FileOperations<int>::convertString(string input) {
    return atoi(input.c_str());
}
template <> string FileOperations<string>::convertString(string input) {
    return input;
}

