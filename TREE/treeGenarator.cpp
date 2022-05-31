#include <iostream>

using namespace std;

struct Node
{
    int  data;
    Node *left;
    Node *right;
};

char make_left = 'l';
char make_right = 'r';
int i;
Node *main_root = NULL;

int pre_order[6] = {1, 2, 4, 5, 3, 6};
int in_order[6] = {4, 2, 5, 1, 6, 3};

int findPosition(char data)
{
    i = 0;
    for (i = 0; i < 10; i++)
    {
        if (in_order[i] == data)
            return i;
    }

    return -1;
}

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
void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
void createTree(Node *root, char direction,
                int pre_start, int pre_stop,
                int in_start, int in_stop)
{
    int position;
    Node *temp = NULL;

    position = findPosition(pre_order[pre_start]);
    
    temp = CreateNode(pre_order[pre_start]);

    if (root == NULL)
    {
        root = temp;
        main_root = temp;
    }
    else if (direction == 'l')
    {
        root->left = temp;
        root = root->left;
    }
    else if (direction == 'r')
    {
        root->right = temp;
        root = root->right;
    }

    if (in_start <= position - 1)
    {
        createTree(root, 'l', pre_start + 1, pre_start + 1 + (position - 1 - in_start),
                   in_start, position - 1);
    }

    if (position + 1 <= in_stop)
    {
        createTree(root, 'r',pre_start + 2 + (position - 1 + in_start), pre_stop,  
        position + 1, in_stop);
    }  
}

int sum(Node * root){
    if(root == NULL){
        return 0;
    }
    return(root->data + sum(root->left)+ sum(root->right));
}

//code for find LCA
// int findLCA(Node *root){

// }
int main()
{
    Node *root = NULL;

    int size = 0;
    createTree(root, 'p', 0, 5, 0, 5);
    printInorder(main_root);
    printf("%d\n", sum(main_root));
    return 0;
}