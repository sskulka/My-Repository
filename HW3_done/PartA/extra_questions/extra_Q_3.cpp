
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

using namespace std;

int main() {
    getchar();
    int iSize = 0;
    uint16_t arrsize;
    //int iTarget = 0;
    vector<int> vArrSoln;
    bool bIsValueExist = false;

    cout << "Please enter a size for array: ";
    cin >> iSize;

    int* raw_input = new int[iSize];

    //inputing values of array from user
    for (int i = 0; i < iSize; i++)
    {
         cout << "Please enter a number: ";
         cin >> raw_input[i];

    }
    //arrsize = ARRAY_SIZE(raw_input);
    
    vector<int> vArrNum(raw_input, raw_input + iSize);

    for (int i : vArrNum) {

        if (i > 10) {
            vArrSoln.push_back(i);
        }
    }

    if (vArrSoln.size() > 1){
        std::vector<int>::iterator itrStruct;

        for (itrStruct = vArrSoln.begin(); itrStruct != vArrSoln.end(); itrStruct++)
        {
            cout << "the values are " << *itrStruct << " " << endl;
            bIsValueExist = true;
        }
        if (!bIsValueExist) {
            cout << "\n No values in array above 10! " << endl;
        }
    }  
    else {
        cout << "\n no values in array!" << endl;
    }

    delete[] raw_input;
    return 0;
}