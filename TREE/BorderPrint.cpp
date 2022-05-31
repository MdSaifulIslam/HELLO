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

void printRightSide(Node *root)
{

    if (root->right != NULL)
    {
        printRightSide(root->right);
        printf("%d ", root->data);
    }
    
}

void printBorder(Node *root)
{
    Node *temp = root;

    while (temp != NULL)
    {
        printf("%d ", temp->data);

        if (temp->right != NULL)
        {
            s.push(temp->right);
        }

        temp = temp->left;
    }

    while (!s.empty())
    {
        temp = s.top();
        s.pop();

        if (temp->left == NULL && temp->right == NULL)
        {
            printf("%d ", temp->data);
        }

        if (temp->right != NULL)
            s.push(temp->right);
        if (temp->left != NULL)
            s.push(temp->left);
    }
    
    printRightSide(root->right);
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

    printBorder(root);
    cout << endl;
    return 0;
}