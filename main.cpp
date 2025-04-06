#include <iostream>

#include "Array.h"
#include "Timer.h"
#include "FileLoader.h"

using namespace std;
int main(int argc, char *argv[]) {

    int a = 0; //Imitacja datatype
    int b = 0; //Imitacja sorttype
    Timer timer = Timer();
    if (a==0) { //INTEGER
        FunctionalArray<int> arrayToSort = FileLoader<int>::loadFile("../a.txt");
        arrayToSort.printArray();
        timer.start();
        arrayToSort.sort(b);
        cout << endl << endl;
        arrayToSort.printArray();
    } else if (a==1) { //
        FunctionalArray<string> arrayToSort = FileLoader<string>::loadFile("../a.txt");
        arrayToSort.printArray();
        timer.start();
        arrayToSort.sort(b);
        cout << endl << endl;
        arrayToSort.printArray();
    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPORTED DATA TYPE" );
    }

    timer.stop();
    cout << "Wynik timera [ms]: " << timer.result() << endl;
    return 0;
}
