#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

char make_left = 'l';
char make_right = 'r';
int i;
Node *main_root = NULL;

int in_order[6] = {4, 2, 5, 1, 6, 3};

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

Node * createTree(Node * node, int data)
{
    if(node == NULL){
        return CreateNode(data);
    }

    if(node->data > data){
        node->left = createTree(node->left, data);
    }
    if(node->data < data){
        node->right = createTree(node->right, data);
    }
    
    return node;
}

Node * minValueNode(Node * node){
    struct Node * current = node;

    while (current !=NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node * deleteNode(Node * node, int data){
    if(node == NULL)
        return NULL;
    
    if(data < node->data){
        node->left = deleteNode(node->left, data);
    }
    else if(data > node->data){
        node->right = deleteNode(node->right, data);
    }else{
        if(node->left == NULL){
            struct Node * temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == NULL){
            struct Node * temp = node->left;
            free(node);
            return temp;
        }

        struct Node * temp = minValueNode(node->right);
        node->data = temp->data;
        
        node->right = deleteNode( node->right, temp->data);
        
    }

    return node;
}

int main()
{
    Node *root = NULL;

    int size = 0, i;
    for(i =0; i<6; i++){
        root = createTree(root, in_order[i]);
    }

    root = deleteNode(root, 3);
    printInorder(root);
    return 0;
}