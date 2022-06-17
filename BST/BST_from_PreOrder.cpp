#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int i;
Node *main_root = NULL;

int in_order[6] = {10, 5, 1, 7, 40, 50};

typedef struct Stack
{
    int top;
    int capacity;
    Node **array;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Node **)malloc(stack->capacity * sizeof(Node *));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, Node *item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

Node *pop(Stack *stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

Node *peek(Stack *stack)
{
    return stack->array[stack->top];
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

Node *createTree()
{
    Stack * stack = createStack(6);
    Node * root = CreateNode(in_order[0]);

    push(stack, root);

    Node * temp;
    for ( i = 1; i < 6; i++)
    {
        temp =NULL;

        while (!isEmpty(stack) && in_order[i] > peek(stack)->data){
            temp = pop(stack);
        }

        if(temp != NULL){
            temp->right = CreateNode(in_order[i]);
            push(stack, temp->right);
        }else{
            peek(stack)->left = CreateNode(in_order[i]);
            push(stack, peek(stack)->left);
        }
    }
    
    return root;
}

Node *minValueNode(Node *node)
{
    struct Node *current = node;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node *deleteNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;

    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
    }
    else
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }

        struct Node *temp = minValueNode(node->right);
        node->data = temp->data;

        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

int main()
{
    Node *root = NULL;
    root = createTree();

    printInorder(root);
    return 0;
}