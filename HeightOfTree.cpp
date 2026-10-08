#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    int height(Node *node)
    {
        if (node == NULL)
            return 0;

        return 1 + max(height(node->left), height(node->right));
    }
};

int main()
{

    Node *root = new Node(11);
    root->left = new Node(21);
    root->right = new Node(32);

    root->left->left = new Node(42);
    root->left->right = new Node(5);

    root->left->right->left = new Node(15);
    root->left->right->right = new Node(51);

    cout << "Height of the tree is "
         << root->height(root);

    cout << "This code is implemented by Abhyudai Gupta " << endl;
}