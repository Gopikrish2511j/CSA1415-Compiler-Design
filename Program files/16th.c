#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char result[20], op1[20], op2[20], op;

    printf("Enter the number of Three Address Code statements: ");
    scanf("%d", &n);

    printf("\nEnter the Three Address Code:\n");
    printf("Example: t1 = a + b\n\n");

    printf("\nTarget Code:\n");
    printf("-------------------------\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s = %s %c %s", result, op1, &op, op2);

        printf("MOV R0, %s\n", op1);

        if (op == '+')
            printf("ADD R0, %s\n", op2);

        else if (op == '-')
            printf("SUB R0, %s\n", op2);

        else if (op == '*')
            printf("MUL R0, %s\n", op2);

        else if (op == '/')
            printf("DIV R0, %s\n", op2);

        printf("MOV %s, R0\n\n", result);
    }

    return 0;
}