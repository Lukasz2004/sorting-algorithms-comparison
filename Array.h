#include <stdlib.h>
using namespace std;
template <typename dataType> class Array {
        public:
                Array(int size) {
                        pointer=(int*) malloc(size*sizeof(int));
                        this->size=size;
                }
                ~Array() {
                        cout << "Destructor of array called" << endl;
                        free(pointer);
                }
                dataType getElement(int index){
                        return *(pointer+sizeof(dataType)*index);
                }
                void setElement(int index, dataType value){
                        *(pointer+sizeof(dataType)*index)=value;
                }
        private:
                dataType* pointer;
                int size;
};
