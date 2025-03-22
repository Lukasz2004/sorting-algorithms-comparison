#include <iostream>

#include "Array.h"
#include "Timer.h"
#include "FileLoader.h"

using namespace std;

int main(int argc, char *argv[]) {

    int a = 0;
    Timer timer = Timer();
    switch (a) {
        case 0:
            Array<int> arrayToSort = FileLoader<int>::loadFile("../a.txt");

            timer.start();
            for (int i=0; i<arrayToSort.size; i++) {
                cout << arrayToSort.getElement(i) << endl;
            }

            timer.stop();
            cout << "Wynik timera [ms]: " << timer.result() << endl;

         break;
    }
    return 0;
}
