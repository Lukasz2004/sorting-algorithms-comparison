#include <fstream>
#include <cstdlib>
#include <sstream>

#include "../array/FunctionalArray.h"

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
    static void saveResultsFile(Array<dataType> *array, string fileName) {
        ofstream file;
        file.open(fileName.c_str());
        file << array->size << endl;
        for (int i = 0; i < array->size; i++) {
            dataType temp = array->getElement(i);
            file << temp << endl;
        }
        file.close();
        return;
    }
    static void saveBenchmarkFile(Array<int> *array, string fileName) {
        ofstream file;
        file.open(fileName.c_str());
        file << array->size << endl;
        for (int i = 0; i < array->size; i++) {
            file << array->getElement(i) << endl;
        }
        file.close();
        return;
    }
    static dataType convertString(string input){};

};

template <> int FileOperations<int>::convertString(string input) {
    return atoi(input.c_str());
}
template <> string FileOperations<string>::convertString(string input) {
    return input;
}
template <> BoardGame FileOperations<BoardGame>::convertString(string input) {
    stringstream ss(input);
    string temp;
    getline(ss, temp,',');
    string name = temp;
    getline(ss, temp,',');
    string publisher = temp;
    getline(ss, temp,',');
    int maxPlayers = atoi(temp.c_str());
    getline(ss, temp,',');
    int playTime = atoi(temp.c_str());
    getline(ss, temp,',');
    int difficultyLevel = atoi(temp.c_str());
    getline(ss, temp,',');
    int happinessFactor = atoi(temp.c_str());
    return BoardGame(name,publisher,maxPlayers,playTime,difficultyLevel,happinessFactor);
}
template <> void FileOperations<BoardGame>::saveResultsFile(Array<BoardGame> *array, string fileName) {
    ofstream file;
    file.open(fileName.c_str());
    file << array->size << endl;
    for (int i = 0; i < array->size; i++) {
        BoardGame temp = array->getElement(i);
        file << temp.name << "," << temp.publisher << ","  << temp.maxPlayers << ","  << temp.playTime << ","  << temp.difficultyLevel << ","  << temp.happinessFactor << endl;
    }
    file.close();
    return;
}