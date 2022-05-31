#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseList(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void insertList(struct node **head)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = i+2;
        newNode->next = *head;
        *head = newNode;
    }
}

void deleteList(struct node **head, int number)
{
    struct node *curr = *head;
    int i;
    struct node *prev = NULL;
    
    for (i = 1; i <= number - 1; i++)
    {
        prev=curr;
        curr = curr->next;
    }

    if (prev == NULL)
    {
        *head = curr->next;
        free(curr);
        return;
    }

    if (curr == NULL)
        return;
    
        
    prev->next = curr->next;
    free(curr);
}
int ElementdeleteFromLast(struct node **head, int number)
{
    struct node *curr = *head;
    int i;
    struct node *prev = *head;
    
    for (i = 1; i <= number - 1; i++)
    {
        if (curr == NULL)
        return -1;
        curr = curr->next;
    }

    while(curr->next != NULL)
    {
        prev = prev->next;
        curr = curr->next;
    }
    
    return prev->data;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    insertList(&head);
    printList(head);

    reverseList(&head);

    deleteList(&head, 1);
    printf("%d\n",ElementdeleteFromLast(&head, 3));

    printList(head);

    return 0;
}
