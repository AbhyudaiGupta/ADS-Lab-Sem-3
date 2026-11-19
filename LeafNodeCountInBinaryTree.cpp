#include <iostream>
using namespace std;
template <typename type>
class Tree
{
    struct Node
    {
        type data;
        Node *left;
        Node *right;

        Node(type d)
        {
            this->data = d;
            this->left = this->right = nullptr;
        }
    };

public:
    Node *Root = nullptr;
    Tree()
    {
        Node *f = new Node('F');
        Node *b = new Node('B');
        Node *g = new Node('G');
        Node *a = new Node('A');
        Node *d = new Node('D');
        Node *i = new Node('I');
        Node *c = new Node('C');
        Node *e = new Node('E');
        Node *h = new Node('H');

        f->left = b;
        f->right = g;

        b->left = a;
        b->right = d;

        g->right = i;

        d->left = c;
        d->right = e;

        i->left = h;

        Root = f;
    }
    // Function to count leaf nodes
    int leafNodeCount(Node *ptr)
    {
        if (ptr == nullptr)
        {
            return 0;
        }

        if (ptr->left == nullptr && ptr->right == nullptr)
        {
            return 1;
        }

        return leafNodeCount(ptr->left) +
               leafNodeCount(ptr->right);
    }
};
int main()
{
    Tree<char> obj;
    int totalNodes = obj.leafNodeCount(obj.Root);
    if (obj.Root == nullptr)
    {
        cout << "Tree is empty!!";
    }
    else
    {
        cout << "Total number of leaf nodes in the binary tree: " << totalNodes << endl;
    }
    cout << "This code is implemented by Abhyudai Gupta " << endl;
}