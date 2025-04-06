template <typename type> class FunctionalArray: public Array<type> {
    public:
        explicit FunctionalArray(int size) : Array<type>(size) {}
        void swap(int index1, int index2) {
            type temp = this->Array<type>::getElement(index1);
            this->Array<type>::setElement(index1, this->Array<type>::getElement(index2));
            this->Array<type>::setElement(index2, temp);
        }
        void printArray() {
            cout << "{";
            for (int i=0; i<Array<type>::size; i++) {
                cout << Array<type>::getElement(i);
                if (i != Array<type>::size-1) {
                    cout << ",";
                }
            }
            cout << "}" << endl;
        }
        void sort(int sortingType) {
            switch (sortingType) {
                case 0:
                    quickSort(0, this->Array<type>::size-1);
                    break;
                case 1:
                    insertionSort();
                    break;
                case 2:
                    heapSort();
                    break;
                default:
                    throw std::invalid_argument( "[Functional Array]: UNSUPORTED SORTING TYPE" );
            }
        }
        void quickSort(int lIndex, int rIndex) {
            int i = lIndex;
            int j = rIndex;
            type x = Array<type>::getElement((lIndex + rIndex ) / 2);
            do
            {
                while( Array<type>::getElement(i) < x ) {
                    i++;
                }
                while( Array<type>::getElement(j) > x ) {
                    j--;
                }
                if(i <= j)
                {
                    swap(i, j);
                    i++;
                    j--;
                }
            } while(i <= j);

            if(lIndex < j) {
                quickSort(lIndex, j);
            }

            if(rIndex > i) {
                quickSort(i, rIndex);
            }
        }
        void insertionSort() {
            for (int i = 1; i < Array<type>::size; i++) {
                int j = i;
                type temp = Array<type>::getElement(i);
                while (j>0 && temp < Array<type>::getElement(j-1)) {
                    j=j-1;
                }

                for (int ii=i; ii>j; ii--) {
                    Array<type>::setElement(ii, Array<type>::getElement(ii-1));
                }
                Array<type>::setElement(j, temp);
            }
        }
        void heapSort() {
            int n;
            for (n=0; n<Array<type>::size; n++) {
                heapifyUp(n,false);
            }
            while (n>1) {
                swap(0,n-1);
                n--;
                heapify(0, n, false);
            }
        }
    private:
        void heapify(int n, int maxn, bool invertToMinHeap) {
            int lIndex = 2*n;
            int rIndex = 2*n+1;
            type largest;
            if (lIndex<maxn && Array<type>::getElement(lIndex) > Array<type>::getElement(n)) {
                largest = lIndex;
            }
            else {
                largest = n;
            }
            if (rIndex<maxn && Array<type>::getElement(rIndex) > Array<type>::getElement(largest)) {
                largest = rIndex;
            }
            if (largest !=n) {
                swap(largest, n);
                heapify(largest, maxn, invertToMinHeap);
            }
        }
        void heapifyUp(int n, bool invertToMinHeap) {
            if (Array<type>::getElement(n) > Array<type>::getElement(n/2)) {
                swap(n/2, n);
                heapifyUp(n/2, invertToMinHeap);
            }
        }
};
