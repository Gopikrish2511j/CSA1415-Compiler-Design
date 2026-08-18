#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expression[100];
char stack[100];
int top = -1;

char postfix[100];
int p = 0;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    return 0;
}

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

/* Convert infix expression to postfix */
void infixToPostfix()
{
    int i;
    char ch;

    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        if (isalnum(ch))
        {
            postfix[p++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[p++] = pop();

            if (top != -1)
                pop();
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/')
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[p++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[p++] = pop();

    postfix[p] = '\0';
}

/* Generate Three Address Code */
void generateTAC()
{
    char operandStack[100][20];
    int operandTop = -1;

    char op1[20], op2[20], temp[20];
    int tempCount = 1;
    int i;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        /* Operand */
        if (isalnum(postfix[i]))
        {
            operandTop++;
            operandStack[operandTop][0] = postfix[i];
            operandStack[operandTop][1] = '\0';
        }

        /* Operator */
        else
        {
            strcpy(op2, operandStack[operandTop--]);
            strcpy(op1, operandStack[operandTop--]);

            sprintf(temp, "t%d", tempCount++);

            printf("%s = %s %c %s\n",
                   temp, op1, postfix[i], op2);

            operandTop++;
            strcpy(operandStack[operandTop], temp);
        }
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%s", expression);

    infixToPostfix();

    printf("\nThree Address Code:\n");
    printf("-------------------\n");

    generateTAC();

    return 0;
}