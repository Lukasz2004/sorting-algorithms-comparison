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
template <typename dataType> void benchmarkMode(int sortType, int arraySize, string outputFilePath)
{
    int maxIterations = 1000;
    cout << "Mode: BENCHMARK" << endl;
    cout << "Iteration amount: " << maxIterations << endl;
    cout << "Test size: " << arraySize << endl;
    cout << "Sorting type: " << sortType << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    cout << "Displaying 5 first results [ms]:" << endl;
    Array<int> benchmarkResultsArray(maxIterations);
    for (int i=0; i<maxIterations; i++) {
        FunctionalArray<dataType> arrayToSort = DataGeneration<dataType>::generateArray(arraySize);
        timer.reset();
        timer.start();
        arrayToSort.sort(sortType);
        //arrayToSort.printArray();
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
int main(int argc, char *argv[]) {
    if (argc == 1 || strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-help" ) == 0) {
        Help::displayHelp();
        return 0;
    }
    srand(time(NULL));
    string inputFilePath = "generatedTest.txt";
    string outputFilePath;
    int runType = atoi(argv[1]);
    int dataType = atoi(argv[2]);//Imitacja datatype
    int sortType, arraySize;
    if (runType==0||runType==1) {
        sortType = atoi(argv[3]); //Imitacja sorttype
        arraySize = atoi(argv[4]);
        string outputFilePath = argv[5];
    }

    cout << "=========================================================" << endl;
    cout << "Starting sortArray program by L.Czerwinski" << endl;
    if (dataType==0) { //INTEGER
        cout << "Data Type: INTEGER" << endl;
        if (runType==0) {singleFileMode<int>(sortType, inputFilePath, outputFilePath);}
        if (runType==1) {benchmarkMode<int>(sortType, arraySize, outputFilePath);}
        if (runType==2) {generateTestFile<int>(atoi(argv[3]), argv[4]);}
    } else if (dataType==1) { //FLOAT
        cout << "Data Type: FLOAT" << endl;
        if (runType==0) {singleFileMode<float>(sortType, inputFilePath, outputFilePath);}
        if (runType==1) {benchmarkMode<float>(sortType, arraySize, outputFilePath);}
        if (runType==2) {generateTestFile<float>(atoi(argv[3]), argv[4]);}
    }
    else if (dataType==2) { //STRING
        cout << "Data Type: STRING" << endl;
        if (runType==0) {singleFileMode<string>(sortType, inputFilePath, outputFilePath);}
        if (runType==1) {benchmarkMode<string>(sortType, arraySize, outputFilePath);}
        if (runType==2) {generateTestFile<string>(atoi(argv[3]), argv[4]);}
    }
    else if (dataType==3) { //BOARDGAMES
        cout << "Data Type: BOARD GAMES" << endl;
        if (runType==0) {singleFileMode<BoardGame>(sortType, inputFilePath, outputFilePath);}
        if (runType==1) {benchmarkMode<BoardGame>(sortType, arraySize, outputFilePath);}
        if (runType==2) {generateTestFile<BoardGame>(atoi(argv[3]), argv[4]);}
    }
    else {
        throw invalid_argument( "[Functional Array]: UNSUPORTED DATA TYPE" );
    }


    return 0;
}
