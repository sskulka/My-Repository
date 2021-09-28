#include <iostream>
#include <vector>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node* left;
    node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

/* Compute the "maxDepth" of a tree.*/
vector<int> FindSum(node* node, int& sum, int parentVal)
{
    if (node == NULL)
    {
        //vector<int> vSum = {sum - parentVal};
        vector<int> vSum = { sum };
        return vSum;
    }
        
    else
    {
        /* compute the depth of each subtree */
        vector<int>vLeftChild = FindSum(node->left, sum, node->data);
        vector<int>vRightChild = FindSum(node->right, sum, node->data);

        //comparing equality of left and right child vectors
        bool result = std::equal(vLeftChild.begin(), vLeftChild.end(), vRightChild.begin());

        //if both vectors are equal. Can happen for a leaf node
        if (result) {
            cout << "\nnode with value" << node->data << "is a leaf" << endl;
            vector<int> vNode;
            std::vector<int>::iterator itrStruct;

            for (itrStruct = vLeftChild.begin(); itrStruct != vLeftChild.end(); itrStruct++)
            {
                vNode.push_back(*itrStruct - node->data); 
            }
            return(vNode);
        }

        //if both vectors are unequal. for non-leaf nodes
        else {
            vector<int> vNode;
            std::vector<int>::iterator itrStructLeft;
            std::vector<int>::iterator itrStructRight;

            for (itrStructLeft = vLeftChild.begin(); itrStructLeft != vLeftChild.end(); itrStructLeft++)
            {
                vNode.push_back(*itrStructLeft - node->data);
            }
            for (itrStructRight = vRightChild.begin(); itrStructRight != vRightChild.end(); itrStructRight++)
            {
                vNode.push_back(*itrStructRight - node->data);
            }
            return(vNode);
        }
    }
}

int main()
{
    node* root = newNode(3);
    int iSum = 30;
    int iZero = 0;
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    //Calling function on the root node
    vector<int> vSoln = FindSum(root, iSum, root->data);

    //traversing the solution to find if a 0 value exists.
    std::vector<int>::iterator itrStructSoln;

    for (itrStructSoln = vSoln.begin(); itrStructSoln != vSoln.end(); itrStructSoln++)
    {
        cout << "\nsolution vector value is" << *itrStructSoln << endl;
        if (*itrStructSoln == iZero) {
            cout << "a set of numbers exist from root to leaf which equals to the sum" << endl;
            return 0;
        }
    }
    //this section will get triggered only when no value in solution vector is 0
    cout << "no set of numbers equals to the sum" << endl;
    return 0;
    
    //cout << "max depth of tree is " << maxDepth(root) - 1;
    
}