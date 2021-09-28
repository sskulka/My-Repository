/*  Nick Sweeting 2013/10/09
    References vs Values in C++
    MIT License
    Takes input and removes puctuation and spaces, using two different methods.
    It is referred from: https://github.com/pirate/Cpp-Data-Structures/
*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#if !defined(ARRAY_SIZE)
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

using namespace std;

//error class for handling duplicate value scenario
class E : public std::exception{
        const char* msg;
        E();
    public:
        E(const char* s) noexcept(true) : msg(s) {}
        const char* what() const noexcept(true) 
        { 
            return msg; 
        }
};

//finds if there are 2 numbers in the array that satisfy the target as their sum
vector<int> findNums(int* arrNum, int iTarget, uint16_t arrsize) {
   
    vector<int> vArrSoln = { 0 };
    vector<int> vArrNum(arrNum, arrNum + arrsize);
    static int k = 0;
    for (int i : vArrNum) {
        std::cout << i << " ";
        for (int j = k + 1; j < vArrNum.size(); j++) {

            int iDiff = iTarget - i;
            if (iDiff == vArrNum[j]) {
                vArrSoln.push_back(vArrNum[j]);
                vArrSoln.push_back(i);
            }
        }
        k++;
    }
    

    return vArrSoln;
}

int main() {
    int iSize = 0;
    int iTarget = 0;
    vector<int> vArrSoln;
    cout << "Please enter a size for array: ";
    cin >> iSize;

    cout << "Please enter a target: ";
    cin >> iTarget;

    int* raw_input = new int[iSize];

    try {
        //inputing values of array from user
        for (int i = 0; i < iSize; i++)
        {
            cout << "Please enter a number: ";
            cin >> raw_input[i];
              
            //iterating through previous elements to check for duplicate value
            for (int j = 0; j < i; j++)
            {
                if (raw_input[i] == raw_input[j])
                {
                    E eValError("Duplicate value found!");
                    throw eValError;
                }
            }
        }
    }
    catch (E& e) {
        std::cout << e.what() << std::endl;
        return 0;
    }
    //uint16_t arrsize = ARRAY_SIZE(raw_input);
    //cout << "size of array using macro is:" << sizeof(raw_input) << endl;

    vArrSoln = findNums(raw_input, iTarget, iSize);

    if(vArrSoln.size()>1)
        cout << "\nsolution is:" << vArrSoln[1] << ", " << vArrSoln[2] << endl;
    else {
        cout << "\n no proper values to have target as sum!" << endl;
    }

    delete[] raw_input;
    return 0;
}