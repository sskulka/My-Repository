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

using namespace std;

struct stTest {
    char ch;
    int pos;
}stTestVar;

// returns true if input character q is puctuation, else false
bool ispunctuation(char q) {
    
    std::vector<char> vPunct = { '.','!',' ','-','_','?','<','>',',','$','#','@','=','+','*','&','^','$','!',';',':','\'','(',')','[',']','{','}','|','`','"'};
    
    std::vector<char>::iterator itData;
    
    for (itData = vPunct.begin(); itData != vPunct.end(); itData++)
    {
        if(*itData == q) return true;
    }
    return false;

}

char* modifyInPlace(char* raw_input) {
    // input cleanup
    vector<stTest> vStruct;
    int q, position = 0;
    for (q = 0; q < 80; q++) {
        if (ispunctuation(raw_input[q])) true;
        else {

            stTestVar = {};

            stTestVar.ch = raw_input[q];
            stTestVar.pos = position;
            vStruct.push_back(stTestVar);
            position++;
        }
        std::vector<stTest>::iterator itrStruct;

        for (itrStruct = vStruct.begin(); itrStruct != vStruct.end(); itrStruct++)
        {
            raw_input[itrStruct->pos] = itrStruct->ch;
        }

    }
    return raw_input;
}

char* modifyAndCopy(char *raw_input, std::string& sTry) {
    // complete the functions here ...
    // input cleanup
    char* newarray = new char[80];
    std::string new_array;
    int q, position = 0;
    for (q = 0; q < 80; q++) {
        if (ispunctuation(raw_input[q])) true;
        else {
            std::stringstream ss;
            std::string sTemp;
            ss << raw_input[q];
            
            ss >> sTemp;

            sTry.append(sTemp);
            position++;
        }
    }
    newarray = &sTry[0];

    return newarray;
}

int main() {
    //getchar();
    // user input
    char raw_input[80] = {0};
    std::string sTry1;
    cout << "Please input something with punctuation in it: ";
    cin.getline(raw_input,80);

    cout << "Modify and Copy: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyAndCopy(raw_input, sTry1) << endl;

    cout << "Modify in Place: " << endl;
    cout << "Original: " << raw_input << endl;
    cout << "Modified: " << modifyInPlace(raw_input) << endl;
}