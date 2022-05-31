#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

stack<Node *> s;

Node *CreateNode(int data)
{
    Node *newNode = new Node();
    if (newNode == NULL)
    {
        cout << "Memory allocation failed" << endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int hightCal(Node *root, int  &size){
    if(root == NULL){
        return 0;
    }

    int l = hightCal(root->left, size);
    int r = hightCal(root->right, size);

    size++;

    return r > l? r+1 : l+1; 
} 

int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->left->right = CreateNode(12);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    int size = 0;
    cout << hightCal(root, size) << endl;
    return 0;
}