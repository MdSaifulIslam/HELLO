#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)
        malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity *
                                 sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char *exp)
{
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;

    int i = 0, k;
    char ch;
    for (i = 0, k = -1; exp[i]; i++)
    {
        ch = exp[i];
        if (isOperand(ch))
        {
            exp[++k] = ch;
        }
        else if (ch == '(')
        {
            push(stack, ch);
        }
        else if (ch == ')')
        {
            while (peek(stack) != '(' && !isEmpty(stack))
            {
                exp[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                return -1;
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && Prec(ch) <= Prec(peek(stack)))
            {
                exp[++k] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while (!isEmpty(stack))
    {
        exp[++k] = pop(stack);
    }
    exp[++k] = '\0';
    printf("%s\n", exp);
    return 0;
}

const char *solveMinus(char *exp, char *output)
{
    int i = 0, k = -1;
    // char output[100];

    if (exp[0] == '-')
    {
        output[++k] = '(';
        output[++k] = '0';
        output[++k] = exp[i++];
        output[++k] = exp[i++];
        output[++k] = ')';
    }

    while (exp[i + 1])
    {

        if (!isOperand(exp[i]) && exp[i + 1] == '-')
        {
            output[++k] = exp[i++];
            output[++k] = '(';
            output[++k] = '0';
            output[++k] = exp[i++];
            output[++k] = exp[i++];
            output[++k] = ')';
        }
        else
        {
            output[++k] = exp[i++];
        }
    }
    while (exp[i])
    {
        output[++k] = exp[i++];
    }

    output[++k] = '\0';

    return output;
}

int main(void)
{
    char exp[] = "-a+b*-c/d+((((-e-f)*-g)+h)*i)";
    char output[100];
    printf("%s\n", solveMinus(exp, output));
    infixToPostfix(output);
    return 0;
}