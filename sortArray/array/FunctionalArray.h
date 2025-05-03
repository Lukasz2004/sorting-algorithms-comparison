#ifndef FUNCTIONAL_ARRAY_H
#define FUNCTIONAL_ARRAY_H
#include "Array.h"
#include <math.h>

template <typename type> class FunctionalArray: public Array<type> {
    public:
        //Constructor - calls constructor of parent
        explicit FunctionalArray(int size) : Array<type>(size) {}
        //Swaps elements at indexes 1 and 2
        void swap(int index1, int index2) {
            type temp = this->Array<type>::getElement(index1);
            this->Array<type>::setElement(index1, this->Array<type>::getElement(index2));
            this->Array<type>::setElement(index2, temp);
        }
        //Reverses array on positions <lIndex,rIndex>. Defaults to entire array
        void reverse(int lIndex=0, int rIndex=Array<type>::size-1) {
            for (int i = lIndex; i <= rIndex; i++) {
                swap(i, rIndex-i);
            }
        }
        //Prints array to std::out
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
        //Checks if the entire array is in ascending(default) or descending order
        bool verifySorted(bool invertToMin=false) {
            for (int i=0; i<Array<type>::size-1; i++) {
                if (invertToMin==false) {
                    //Ascending Order
                    if (Array<type>::getElement(i) > Array<type>::getElement(i+1)) {
                        throw runtime_error("[Functional Array]: ARRAY INCORECTLY SORTED");
                        return false;
                    }
                }
                else {
                    //Descending Order
                    if (Array<type>::getElement(i) < Array<type>::getElement(i+1)) {
                        throw runtime_error("[Functional Array]: ARRAY INCORECTLY SORTED");
                        return false;
                    }
                }
            }
            return true;
        }
        //Sorts the array using algorythms provided in the parameters
        void sort(int sortingType=0, int param=-1) {
            switch (sortingType) {
                case 0: //QuickSort
                    if (param==-1){param=2;} //Default Param
                    quickSort(0, this->Array<type>::size-1,param);
                    break;
                case 1: //InsertionSort
                    insertionSort(1);
                    break;
                case 2: //HeapSort
                    heapSort();
                    break;
                case 3: //ShellSort
                    if (param==-1){param=1;} //Default Param
                    shellSort(param,100);
                    break;
                case 4: //CrazySort
                    if (param==-1){param=100;}//DefaultParam
                    crazySort(param);
                    break;
                default: //Invalid Sort
                    throw std::invalid_argument( "[Functional Array]: UNSUPPORTED SORTING TYPE" );
            }
        }
        //Sorts only first percentage of the array using QuickSort
        void partialSort(int percentage) {
            if (percentage<-100||percentage>100) {
                throw std::invalid_argument( "[Functional Array]: INVALID PRESORT PERCENTAGE" );
            }
            quickSort(0, (this->Array<type>::size-1)*abs(percentage)/100,3);
            if (percentage<0) {
                reverse(0,(this->Array<type>::size-1)*abs(percentage)/100);
            }
        }
        void quickSort(int lIndex, int rIndex, int pivotType) {
            int i = lIndex;
            int j = rIndex;
            type x;
            //Choose the pivot
            switch (pivotType) {
                case 0: //Left
                    x = this->Array<type>::getElement(lIndex);
                    break;
                case 1: //Right
                    x = this->Array<type>::getElement(rIndex);
                    break;
                case 2: //Middle
                    x = Array<type>::getElement((lIndex + rIndex ) / 2);
                    break;
                case 3: //Random
                    x = Array<type>::getElement(rand()%(rIndex-lIndex)+lIndex);
                    break;
                default:
                    throw std::invalid_argument( "[Functional Array]: INVALID SORTING PARAM" );
            }

            //Find smaller and larger elements
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

            //Call QS for next pivots
            if(lIndex < j) {
                quickSort(lIndex, j, pivotType);
            }

            if(rIndex > i) {
                quickSort(i, rIndex, pivotType);
            }
        }

        void shellSort(int gapType, int correctnessPercentage) {
            switch (gapType) {
                case 0: //floor(n/2^k)
                    for (int gap = Array<type>::size/2; gap > 0; gap /= 2)
                    {
                        insertionSort(gap);
                    }
                    break;
                case 1: //2^k -1
                    for (int gap = pow(2, ceil(log(Array<type>::size)/log(2)))/2; gap > 0; gap /= 2)
                    {
                        insertionSort(gap-1);
                    }
                    break;
                case 2: //CrazySort - floor(n/2^k) with mistakes
                    try
                    {
                        bool event = rand()%101 > correctnessPercentage; //Chance of mistake
                        for (int gap = Array<type>::size/2; gap > 0; gap /= 2)
                        {
                            if (!event) { //If mistake didnt happen
                                insertionSort(gap);
                            }
                            else { //If mistake happened, randomise the gap
                                insertionSort(rand()%(Array<type>::size-2)+1);
                            }
                        }
                        verifySorted(false);
                    }
                    catch(runtime_error) {
                        shellSort(gapType, correctnessPercentage);
                    }
                    break;
                default:
                    throw std::invalid_argument( "[Functional Array]: INVALID SORTING PARAM" );
            }
        }
        void crazySort(int percentage) {
            if (percentage<1||percentage>100) {   //Invalid Param
                throw std::invalid_argument("[Functional Array]: INCORRECT SORTING PARAM");
            }
            shellSort(2, percentage);
        }
        void insertionSort(int gap) {
            for (int a=0; a<gap; a++) {
                for (int i = a+gap; i < Array<type>::size; i=i+gap) {
                    int j = i;
                    type temp = Array<type>::getElement(i);
                    while (j>= gap && temp < Array<type>::getElement(j-gap)) {
                        j=j-gap;
                    }

                    for (int ii=i; ii>j; ii=ii-gap) {
                        Array<type>::setElement(ii, Array<type>::getElement(ii-gap));
                    }
                    Array<type>::setElement(j, temp);
                }
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