#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
queue<Node *> q;

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

void printDiagonal(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    q.push(root->left);
    printDiagonal(root->right);
}

void diagonal(Node *root)
{
    q.push(root);
    Node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        printDiagonal(temp);
    }
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

    diagonal(root);
    cout << endl;
    return 0;
}