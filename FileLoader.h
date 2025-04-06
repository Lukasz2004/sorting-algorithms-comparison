#include <fstream>
#include <stdlib.h>
#include <typeinfo>

#include "FunctionalArray.h"

template <typename dataType> class FileLoader {
    public:
        static FunctionalArray<dataType> loadFile(string filename) {
            ifstream file;
            file.open(filename.c_str());
            string tempInput;
            getline(file, tempInput);
            int numberOfLines = atoi(tempInput.c_str());
            FunctionalArray<dataType> tempArray = FunctionalArray<dataType>(numberOfLines);
            for (int i = 0; i < numberOfLines; i++) {
                getline(file, tempInput);
                tempArray.setElement(i, convertString(tempInput));
            }
            return tempArray;
        }

        static dataType convertString(string a) {
            if (typeid(dataType) == typeid(int)) {
                return atoi(a.c_str());
            }
        }

};
