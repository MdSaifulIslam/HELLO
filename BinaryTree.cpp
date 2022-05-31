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

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

void deleteLastNode(Node *root, Node *node)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    Node *temp = NULL;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == node)
        {
            temp = NULL;
            delete (node);
            return;
        }

        if (temp->left != NULL)
        {
            if (temp->left == node)
            {
                temp->left = NULL;
                delete (node);
                return;
            }
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            if (temp->right == node)
            {
                temp->right = NULL;
                delete (node);
                return;
            }
            q.push(temp->right);
        }
    }
}

Node * deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == data)
        {
            printf("Deleting root node\n");
            return NULL;
        }
        else
        {
            return root;
        }
    }

    queue<Node *> q;
    q.push(root);

    Node *temp;
    Node *key_node = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == data)
        {
            key_node = temp;
        }

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    if (key_node == NULL)
    {
        return root;
    }
    else
    {
        int x = temp->data;
        printf("last  node  data %d\n", x);
        deleteLastNode(root, temp);
        key_node->data = x; 
    }
    return root;
}

int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    inorder(root);
    cout << endl;

    deleteNode(root, 10);
    inorder(root);
    cout << endl;
    deleteNode(root, 8);
    inorder(root);
    cout << endl;
    deleteNode(root, 9);
    inorder(root);
    cout << endl;

    return 0;
}