#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    stack[++top] = value;
}

// Pop operation
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If operand, push onto stack
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        // If operator, pop two operands and evaluate
        else
        {
            op2 = pop();
            op1 = pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '%':
                    result = op1 % op2;
                    break;

                default:
                    printf("Invalid Operator\n");
                    return 1;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}