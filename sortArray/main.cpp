#include <algorithm>
#include <iostream>
#include <string.h>
#include <typeinfo>

#include "boardGames/BoardGame.h"
#include "data/DataGeneration.h"
#include "timer/Timer.h"
#include "data/FileOperations.h"
#include "help/Help.h"

using namespace std;
Timer timer;
template <typename dataType> void generateTestFile(int size, string outputFilePath)
{
    cout << "Mode: GENERATE TEST" << endl;
    cout << "Test size: " << size << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    FunctionalArray<dataType> generatedArray = DataGeneration<dataType>::generateArray(size);
    FileOperations<dataType>::saveResultsFile(&generatedArray, outputFilePath);
    cout << "Successly saved to " << outputFilePath << endl;
}
template <typename dataType> void singleFileMode(int sortType, string inputFilePath, string outputFilePath)
{
    FunctionalArray<dataType> arrayToSort = FileOperations<dataType>::loadFile(inputFilePath);

    cout << "Mode: SINGLE FILE" << endl;
    cout << "Test size: " << arrayToSort.size << endl;
    cout << "Sorting type: " << sortType << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    cout << "Loaded array:" << endl;
    arrayToSort.printArray();

    timer.start();
    arrayToSort.sort(sortType);
    timer.stop();

    arrayToSort.verifySorted(false);
    cout << endl << endl;
    cout << "Sorted array:" << endl;
    arrayToSort.printArray();

    arrayToSort.verifySorted(false);
    cout << "Timer result [ms]: " << timer.result() << endl;
    FileOperations<dataType>::saveResultsFile(&arrayToSort,outputFilePath);
}
template <typename dataType> void benchmarkMode(int sortType, int arraySize, string outputFilePath, int sortParam=-1, int presortPercentage=0)
{
    int maxIterations = 1000;
    cout << "Mode: BENCHMARK" << endl;
    cout << "Iteration amount: " << maxIterations << endl;
    cout << "Test size: " << arraySize << endl;
    cout << "Sorting type: " << sortType << endl;
    if (sortParam!=-1) {
        cout << "Sorting param: " << sortParam << endl;
    }
    if (presortPercentage!=0) {
        cout << "Presort percentage: " << presortPercentage << "%" << endl;
    }
    cout << "=========================================================" << endl;
    cout << endl;
    cout << "Displaying 5 first results [ms]:" << endl;
    Array<int> benchmarkResultsArray(maxIterations);
    for (int i=0; i<maxIterations; i++) {
        FunctionalArray<dataType> arrayToSort = DataGeneration<dataType>::generateArray(arraySize);

        if (presortPercentage!=0){arrayToSort.partialSort(presortPercentage);}
        timer.reset();

        timer.start();
        arrayToSort.sort(sortType, sortParam);
        timer.stop();

        arrayToSort.verifySorted(false);
        if (i<=4) {
            cout << timer.result();
            if (i==4) {
                cout << endl << "All the results will be available in a .txt file " << endl << endl;
            }
            else {
                cout << ", ";
            }
        }
        if (((i+1)*100)%(10*maxIterations)==0) {
            cout << "Progress: " << ((i+1)*100/maxIterations) << "%" << endl;
        }
        benchmarkResultsArray.setElement(i, timer.result());
    }
    FileOperations<dataType>::saveBenchmarkFile(&benchmarkResultsArray,outputFilePath);
}
template <typename dataType> void parameterModeBenchmark(int sortType, int arraySize, string outputFilePath, int parameter) {

}
template <typename dataType> void chooseMode(int argc, char *argv[]) {
    string runType = argv[1];

    string inputFilePath = "generatedTest.txt";
    if (runType=="--single") {singleFileMode<dataType>(atoi(argv[3]), inputFilePath, argv[5]);}
    else if (runType=="--benchmark") {
        int sortType = atoi(argv[3]);
        int arraySize = atoi(argv[4]);
        string outputFilePath = argv[5];
        int sortParam = -1;
        int presortPercentage = 0;
        for (int i=6; i<argc; i++) {
            string temp = argv[i];
            if (temp=="-arg") {
                string temp2 = argv[i+1];
                sortParam = atoi(temp2.c_str());
            }
            if (temp=="-pre") {
                string temp2 = argv[i+1];
                presortPercentage = atoi(temp2.c_str());
            }
        }

        benchmarkMode<dataType>(sortType,arraySize, outputFilePath, sortParam, presortPercentage);
    }
    else if (runType=="--generate") {generateTestFile<dataType>(atoi(argv[3]), argv[4]);}
    else {
        cout << endl << endl << endl << "Invalid Parameters, displaying help" << endl;
        Help::displayHelp();
        return;
    }
}
int main(int argc, char *argv[]) {
    if (argc == 1 || strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-help" ) == 0) {
        Help::displayHelp();
        return 0;
    }
    srand(time(NULL));
    int dataType = atoi(argv[2]);//Imitacja datatype

    cout << "=========================================================" << endl;
    cout << "Starting sortArray program by L.Czerwinski" << endl;
    if (dataType==0) { //INTEGER
        cout << "Data Type: INTEGER" << endl;
        chooseMode<int>(argc,argv);
    } else if (dataType==1) { //FLOAT
        cout << "Data Type: FLOAT" << endl;
        chooseMode<float>(argc,argv);
    }
    else if (dataType==2) { //STRING
        cout << "Data Type: STRING" << endl;
        chooseMode<string>(argc,argv);
    }
    else if (dataType==3) { //BOARDGAMES
        cout << "Data Type: BOARD GAMES" << endl;
        chooseMode<BoardGame>(argc,argv);
    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPPORTED DATA TYPE" );
    }


    return 0;
}
