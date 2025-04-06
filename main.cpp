#include <iostream>

#include "Array.h"
#include "Timer.h"
#include "FileOperations.h"

using namespace std;

template <typename dataType> void algorythm(Timer *timer, string filePath, int sortType)
{
    FunctionalArray<dataType> arrayToSort = FileOperations<dataType>::loadFile(filePath);
    arrayToSort.printArray();
    timer->start();
    arrayToSort.sort(sortType);
    cout << endl << endl;
    arrayToSort.printArray();
    timer->stop();
    cout << "Wynik timera [ms]: " << timer->result() << endl;
    FileOperations<dataType>::saveFile(&arrayToSort,"b.txt");
}
int main(int argc, char *argv[]) {

    string filePath = "a.txt";
    int dataType = 0; //Imitacja datatype
    int sortType = 0; //Imitacja sorttype
    Timer timer = Timer();
    if (dataType==0) { //INTEGER
        algorythm<int>(&timer, filePath, sortType);
    } else if (dataType==1) { //
        algorythm<string>(&timer, filePath, sortType);
    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPORTED DATA TYPE" );
    }


    return 0;
}
