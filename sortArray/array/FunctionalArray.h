#ifndef FUNCTIONAL_ARRAY_H
#define FUNCTIONAL_ARRAY_H
#include "Array.h"
#include <math.h>

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
        bool verifySorted(bool invertToMin) {
            for (int i=0; i<Array<type>::size-1; i++) {
                if (Array<type>::getElement(i) > Array<type>::getElement(i+1)) {
                    throw runtime_error("[Functional Array]: ARRAY INCORECTLY SORTED");
                    return false;
                }
            }
            return true;
        }
        void sort(int sortingType) {
            switch (sortingType) {
                case 0:
                    quickSort(0, this->Array<type>::size-1,2);
                    break;
                case 1:
                    insertionSort(1);
                    break;
                case 2:
                    heapSort();
                    break;
                case 3:
                    shellSort(1);
                    break;
                default:
                    throw std::invalid_argument( "[Functional Array]: UNSUPORTED SORTING TYPE" );
            }
        }
        void quickSort(int lIndex, int rIndex, int pivotType) {
            int i = lIndex;
            int j = rIndex;
            type x;
            if (pivotType==0) //Left
            {
                x = Array<type>::getElement(lIndex);
            }
            if (pivotType==1) //Right
            {
                x = Array<type>::getElement(rIndex);
            }
            if (pivotType==2) //Middle
            {
                x = Array<type>::getElement((lIndex + rIndex ) / 2);
            }
            if (pivotType==3) //Random
            {
                x = Array<type>::getElement(rand()%(rIndex-lIndex)+lIndex);
            }
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
                quickSort(lIndex, j, pivotType);
            }

            if(rIndex > i) {
                quickSort(i, rIndex, pivotType);
            }
        }

        void shellSort(int gapType) {
            if (gapType==0) {
                for (int gap = Array<type>::size/2; gap > 0; gap /= 2)
                {
                    insertionSort(gap);
                }
            }
            if (gapType==1) {
                for (int gap = pow(2, ceil(log(Array<type>::size)/log(2))); gap > 0; gap /= 2)
                {
                    cout << "GAAP" << gap << endl;
                    insertionSort(gap-1);
                }
            }
        }
        void insertionSort(int gap) {
            for (int i = gap; i < Array<type>::size; i++) {
                int j = i;
                type temp = Array<type>::getElement(i);
                while (j> 0 && temp < Array<type>::getElement(j-gap)) {
                    j=j-gap;
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
            int largest;
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
#endif