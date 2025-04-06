using namespace std;
template <typename dataType> class Array {
        public:
                Array(int size) {
                        cout << "Constructing array of size: " << size << endl;
                        pointer = new dataType[size*sizeof(dataType)];
                        this->size=size;
                        cout << "Success" << endl;
                }
                ~Array() {
                        cout << "Destructing array of size: " << this->size << endl;
                        delete[] pointer;
                }
                dataType getElement(int index){
                        return *(pointer+sizeof(dataType)*index);
                }
                void setElement(int index, dataType value){
                        *(pointer+sizeof(dataType)*index)=value;
                }
                dataType& operator[](int index) {
                        return *(pointer+sizeof(dataType)*index);
                }
                int size;
        private:
                dataType* pointer;

};
