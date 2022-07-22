#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int compare(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}

int countNodes(struct  node *root)
{
    if(root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}


void storeInorder(struct node * root, int arr[], int *index)
{
    if(root == NULL)
        return;

    storeInorder(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++;
    storeInorder(root->right, arr, index);
}

void arrayToBST (int arr[], struct node *root, int *index)
{
    if(root == NULL){
        return;
    }
    arrayToBST(arr, root->left, index);
    root->data = arr[*index];
    (*index) ++;
    arrayToBST(arr, root->right, index);
}

void binaryTreeToBST(struct node *root)
{
    if (root == NULL)
        return;

    int n = countNodes(root);

    int *arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);

    qsort(arr, n, sizeof(arr[0]), compare);

    i = 0;
    arrayToBST(arr, root, &i);

    delete [] arr;
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
 
    printf("%d ", node->data);
 
    printInorder(node->right);
}

int main()
{
    struct node *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    binaryTreeToBST(root);

    printInorder(root);

    return 0;
}