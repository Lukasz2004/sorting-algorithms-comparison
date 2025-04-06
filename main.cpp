#include <iostream>

#include "Array.h"
#include "Timer.h"
#include "FileLoader.h"

using namespace std;
int main(int argc, char *argv[]) {

    int a = 0; //Imitacja datatype
    int b = 2; //Imitacja sorttype
    Timer timer = Timer();
    if (a==0) { //INTEGER
        FunctionalArray<int> arrayToSort = FileLoader<int>::loadFile("../a.txt");
        for (int i=0; i<arrayToSort.size; i++) {
            cout << arrayToSort.getElement(i) << endl;
        }
        timer.start();
        arrayToSort.sort(b);
    } else if (a==1) { //
        return a;
    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPORTED DATA TYPE" );
    }

    timer.stop();
    cout << "Wynik timera [ms]: " << timer.result() << endl;
    return 0;
}
