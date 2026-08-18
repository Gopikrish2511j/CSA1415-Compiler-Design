#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[100];
    char ch;

    int characters = 0;
    int words = 0;
    int lines = 0;
    int inWord = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        /* Count lines */
        if (ch == '\n')
        {
            lines++;
        }

        /* Count words */
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    fclose(fp);

    /* If the file is not empty and doesn't end with newline */
    if (characters > 0 && ch != '\n')
    {
        lines++;
    }

    printf("\n----- FILE ANALYSIS -----\n");
    printf("Number of characters : %d\n", characters);
    printf("Number of words      : %d\n", words);
    printf("Number of lines      : %d\n", lines);

    return 0;
}