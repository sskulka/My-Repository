#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class LinkedList {
    int iValue;
    
public:
    LinkedList* pNext;
    LinkedList(int iValue, LinkedList* pNext) : iValue(iValue), pNext(pNext) {}

    static vector<int> displayLinkedList(vector<LinkedList>& vfirstList)
    {
        vector<int> vLinkedListVals;

        std::vector<LinkedList>::iterator itrStruct;
        int i = 1;
        for (itrStruct = vfirstList.begin(); itrStruct != vfirstList.end(); itrStruct++)
        {

            while (itrStruct->pNext != NULL) {
                vLinkedListVals.push_back(itrStruct->iValue);
                *itrStruct = *itrStruct->pNext;
            }
            vLinkedListVals.push_back(itrStruct->iValue);
        }



        return vLinkedListVals;
    }
};

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    while ((int)left.size() > 0 || (int)right.size() > 0) {
        if ((int)left.size() > 0 && (int)right.size() > 0) {
            if ((int)left.front() <= (int)right.front()) {
                result.push_back((int)left.front());
                left.erase(left.begin());
            }
            else {
                result.push_back((int)right.front());
                right.erase(right.begin());
            }
        }
        else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
        }
        else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    return result;
}

vector<int> mergeSort(vector<int> m)
{
    if (m.size() <= 1)
        return m;

    vector<int> left, right, result;
    int middle = ((int)m.size() + 1) / 2;

    for (int i = 0; i < middle; i++) {
        left.push_back(m[i]);
    }

    for (int i = middle; i < (int)m.size(); i++) {
        right.push_back(m[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);

    return result;
}



int main()
{
    //getchar();
    std::string raw_input;
    int k = 0;

    /*cout << "Please input number of Linked lists to initiate: ";
    getline(cin, raw_input);
    stringstream raw_stream(raw_input);
    raw_stream >> k;*/

    //creating first linked list
    LinkedList l1_1(2, NULL);
    LinkedList l1_2(7, NULL);
    LinkedList l1_3(5, NULL);
    l1_1.pNext = &l1_2;
    l1_2.pNext = &l1_3;

    //creating second linked list
    LinkedList l2_1(8, NULL);
    LinkedList l2_2(3, NULL);
    LinkedList l2_3(1, NULL);
    l2_1.pNext = &l2_2;
    l2_2.pNext = &l2_3;

    //creating third linked list
    LinkedList l3_1(1, NULL);
    LinkedList l3_2(12, NULL);
    LinkedList l3_3(6, NULL);
    l3_1.pNext = &l3_2;
    l3_2.pNext = &l3_3;

    vector<LinkedList> vLinkedLists;
    vLinkedLists.push_back(l1_1);
    vLinkedLists.push_back(l2_1);
    vLinkedLists.push_back(l3_1);

    vector<int> vLinkedListVals = LinkedList::displayLinkedList(vLinkedLists);

    vector<int> vSorted = mergeSort(vLinkedListVals);

    std::vector<int>::iterator itrStruct;
    int i = 1;
    for (itrStruct = vSorted.begin(); itrStruct != vSorted.end(); itrStruct++)
    {

        cout << "\n" << i << "th value of linkedlist is: " << *itrStruct << endl;
        i++;
    }

    return 0;
}