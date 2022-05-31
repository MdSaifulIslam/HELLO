#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

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

Node *Insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = CreateNode(data);
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = CreateNode(data);
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }

    return root;
}

void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int main()
{
    Node* root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = Insert(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}