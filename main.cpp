#include <iostream>

#include "Array.h"
#include "Timer.h"

using namespace std;
int main(int argc, char *argv[]) {

    Timer timer = Timer();
    timer.start();


    Array<int> b(10);
    for (int i = 0; i < 10; i++) {
        b.setElement(i,(char) 'a' + i);
        cout << (char) b.getElement(i) << endl;
    }


    timer.stop();
    cout << "Wynik timera [ms]: " << timer.result() << endl;


    return 0;
}
