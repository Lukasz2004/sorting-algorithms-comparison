#include <iostream>

#include "Array.h"
#include "Timer.h"

using namespace std;
int main(int argc, char *argv[]) {
    Timer timer = Timer();
    Array<int> a(10);
    timer.start();
    for (int i = 1; i <= 10; i++) {
        cout << i << std::endl;
    }
    timer.stop();
    cout << timer.result() << endl;



    for (int i = 0; i < 10; i++) {
        a.setElement(i, i);
        cout << a.getElement(i) << endl;
    }
    //a.destroy();
    return 0;
}
