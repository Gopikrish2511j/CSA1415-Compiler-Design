#include <stdio.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void match(char ch)
{
    if (input[pos] == ch)
        pos++;
    else
        error = 1;
}

/* E -> T E' */
void E()
{
    T();
    Eprime();
}

/* E' -> + T E' | epsilon */
void Eprime()
{
    if (input[pos] == '+')
    {
        match('+');
        T();
        Eprime();
    }
}

/* T -> F T' */
void T()
{
    F();
    Tprime();
}

/* T' -> * F T' | epsilon */
void Tprime()
{
    if (input[pos] == '*')
    {
        match('*');
        F();
        Tprime();
    }
}

/* F -> ( E ) | id */
void F()
{
    /* Check for id */
    if (input[pos] == 'i' && input[pos + 1] == 'd')
    {
        pos = pos + 2;
    }

    /* Check for ( E ) */
    else if (input[pos] == '(')
    {
        match('(');
        E();
        match(')');
    }

    else
    {
        error = 1;
    }
}

int main()
{
    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if (error == 0 && input[pos] == '\0')
    {
        printf("\nThe string satisfies the grammar.\n");
        printf("Valid String\n");
    }
    else
    {
        printf("\nThe string does not satisfy the grammar.\n");
        printf("Invalid String\n");
    }

    return 0;
}