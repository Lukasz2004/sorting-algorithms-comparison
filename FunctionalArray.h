template <typename type> class FunctionalArray: public Array<type> {
    public:
        explicit FunctionalArray(int size) : Array<type>(size) {}
        void sort(int sortingType) {
            switch (sortingType) {
                case 0:
                    bubbleSort();
                    break;
                case 1:
                    break;
                default:
                    throw std::invalid_argument( "[Functional Array]: UNSUPORTED SORTING TYPE" );
            }
        }
        void bubbleSort() {
            for (int i = 1; i < this->size; i++) {
                for (int j = i; j > 0; j--) {
                    if (this->getElement(j - 1) > this->getElement(j)) {
                        type temp = this->getElement(j - 1);
                        this->setElement(j - 1, this->getElement(j));
                        this->setElement(j, temp);
                    }
                }
            }
        }
};
