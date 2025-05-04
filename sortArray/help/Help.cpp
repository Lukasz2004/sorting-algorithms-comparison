#include "Help.h"

#include <iostream>
#include <ostream>

using namespace std;
void Help::displayHelp() {
    cout << "=========================================================" << endl;
    cout << "sortArray program by L.Czerwinski - Help:" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Single File Test Mode:" << endl;
    cout << "> ./sortArray.exe --single <dataType> <inputFilePath> <outputFilePath>" << endl;
    cout << "Benchmark Mode:" << endl;
    cout << "> ./sortArray.exe --benchmark <dataType> <sortType> <arraySize> <outputFilePath> [?-arg sortingParameter] [?-pre percentage]" << endl;
    cout << "Generate Test Data Mode:" << endl;
    cout << "> ./sortArray.exe --generate <dataType> <arraySize> <outputFilePath>" << endl;
    cout << "Display Help:" << endl;
    cout << "> ./sortArray.exe --help" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "<dataType> - specifies data type to load. Available: " << endl
    << "[0] Integer, [1] Float, [2] String, [3] BoardGames" << endl;
    cout << "<sortType> - specifies sorting algorithm to use. Available: " << endl
    << "[0] QuickSort, [1] InsertionSort, [2] HeapSort, [3] ShellSort, [4*] CrazySort" << endl
    << "*-only in Benchmark Mode" << endl;
    cout << "<arraySize> - specifies the number of elements in arrays that will be generated" << endl;
    cout << "<inputFilePath> - path to load the data from. First row should contain number of elements. Each element should be in a separate row." << endl;
    cout << "<outputFilePath> - path to save the results to (Single - sorted Array, Benchmark - times of execution, Generate - array to be sorted)." << endl;
    cout << "[?-arg sortingParameter] - modifies how the algorythm behaves. Optional, defaults to most effective. Available modifiers:" << endl <<
        "CrazySort (percentage of failure [1-100]), QuickSort (pivot choosing method [0-2]), ShellSort (gap selection algorythm [0-1]) "<< endl;
    cout << "[?-pre percentage] - allows for the generated data to be partially sorted. Optional, defaults to 0. The percentage (in range between -100 and 100) specifies how many elements will be presorted (0 to size*percentage/100). Negative values will sort the array in descending order." << endl;;
    cout << "=========================================================" << endl;
}
