#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct findInts {
	int endValue;
	int StartValue;
};

vector<findInts> findNums(int* arrNum, int iTarget, uint16_t arrsize) {

	vector<findInts> vArrSoln;

	vector<int> vArrNum(arrNum, arrNum + arrsize);
	static int k = 0;
	//for (int i : vArrNum) {
	for (int i = 0; i < vArrNum.size(); i++) {
		//i = i + k;
		//create a vector which has it's values as the contents of the int array
		int intTemp = iTarget;
		for (int j = i; j < vArrNum.size(); j++) {

			intTemp = intTemp - vArrNum[j];
			if (intTemp == 0)
			{
				findInts structTemp;
				structTemp.endValue = j + 1;
				structTemp.StartValue = i + 1;

				vArrSoln.push_back(structTemp);
			}

		}
		//k++;
	}
	return vArrSoln;
}

int main() {
	std::string raw_input;
	int iSize = 0;
	int iTarget = 0;
	int maxEndVal = 0;
	int maxStartVal = 0;
	vector<findInts> vArrSoln;

	cout << "Please input array size: ";
	getline(cin, raw_input);
	stringstream raw_stream(raw_input);
	
	raw_stream >> iSize;
	int* input_array = new int[iSize];

	//inputing values of array from user
	for (int i = 0; i < iSize; i++)
	{
		cout << "Please enter a number: ";
		cin >> input_array[i];
	}
	cout << "Please enter a target: ";
	cin >> iTarget;

	vArrSoln = findNums(input_array, iTarget, iSize);

	std::vector<findInts>::iterator itrStruct;

	for (itrStruct = vArrSoln.begin(); itrStruct != vArrSoln.end(); itrStruct++)
	{
		if (maxEndVal < itrStruct->endValue)
		{
			maxEndVal = itrStruct->endValue;
			maxStartVal = itrStruct->StartValue;
		}
	}
	if (maxStartVal != 0 && maxEndVal != 0)
	{
		cout << "\nmax end value index is:" << maxEndVal << " & max start value index is:" << maxStartVal << endl;
		cout << "Numbers are: ";
		for (int i = maxStartVal - 1; i <= maxEndVal - 1; i++)
		{
			cout << input_array[i];
			if (i != maxEndVal - 1)
				cout << ", ";
		}
	}
	else
		cout << "No numbers matching the target value. ";
}

