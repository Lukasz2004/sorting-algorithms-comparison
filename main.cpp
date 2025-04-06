#include <iostream>

#include "Array.h"
#include "Timer.h"
#include "FileOperations.h"

using namespace std;
int main(int argc, char *argv[]) {

    string filePath = "a.txt";
    int dataType = 0; //Imitacja datatype
    int sortType = 0; //Imitacja sorttype
    Timer timer = Timer();
    if (dataType==0) { //INTEGER
        FunctionalArray<int> arrayToSort = FileOperations<int>::loadFile(filePath);
        arrayToSort.printArray();
        timer.start();
        arrayToSort.sort(sortType);
        cout << endl << endl;
        arrayToSort.printArray();
        timer.stop();
        cout << "Wynik timera [ms]: " << timer.result() << endl;
        FileOperations<int>::saveFile(&arrayToSort,"b.txt");
    } else if (dataType==1) { //
        FunctionalArray<string> arrayToSort = FileOperations<string>::loadFile(filePath);
        arrayToSort.printArray();
        timer.start();
        arrayToSort.sort(sortType);
        cout << endl << endl;
        arrayToSort.printArray();

    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPORTED DATA TYPE" );
    }


    return 0;
}
