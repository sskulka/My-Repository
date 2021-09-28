#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    std::vector<std::string> vSolutions;
    std::string raw_input;
    std::string sTry1;
    cout << "Please input something with punctuation in it: ";
    getline(cin, raw_input);
    int len = raw_input.length();
    for (int m = 0; m < len - 1; m++)
    {
        int h_len = (len - m) / 2;

        for (int i = 0; i < h_len; i++)
        {
            string a1 = raw_input.substr(m, i + 1);
            for (int k = 0; k < len - 2 * i - 1 - m; k++)
            {
                string a2 = raw_input.substr(i + 1 + k + m, i + 1);
                if (a1 == a2 && a1.length() >= 3) {
                    vSolutions.push_back(a1);
               }
            }

        }
    }
    auto it = std::max_element(vSolutions.begin(), vSolutions.end(),
        [](std::string& a, std::string& b) {
            return a.size() < b.size();
        });
    cout << "duplicate string found:" << *it << endl;
    
	return 0;
}