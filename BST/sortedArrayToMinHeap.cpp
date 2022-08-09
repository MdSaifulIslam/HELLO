
#include <bits/stdc++.h>
using namespace std;

// Node for BST/Min-Heap
struct Node
{
    int data;
    Node *left, *right;
};
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

Node *SortedArrayToMinHeap()
{
    queue<Node *> q;
    Node *root = NULL;
    int i = 0, lenght = 10;
    if (root == NULL)
    {
        root = newNode(arr[i]);
    }

    q.push(root);

    while (!q.empty() && i < lenght)
    {
        Node *temp = q.front();
        q.pop();

        if (i + 1 < lenght)
        {
            temp->left = newNode(arr[i + 1]);
            q.push(temp->left);
        }
        else
            return root;

        if (i + 2 < lenght)
        {
            temp->right = newNode(arr[i + 2]);
            q.push(temp->right);
        }
        else
            return root;
        i += 2;
    }

    return root;
}

void printInOrder(Node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    printInOrder(root->left);
    
    printInOrder(root->right);
}

int main()
{
    Node *root = SortedArrayToMinHeap();
    printLevelOrder(root);

    printInOrder(root);

    return 0;
}
