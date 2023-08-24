#include <stdio.h>

void find_comments(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return;
    }

    char line[2000];
    int line_number = 0;
    int multilinecomment = 0;

    while (fgets(line, sizeof(line), file))
    {
        line_number++;

        for (int i = 0; line[i] != '\0'; i++)
        {
            if (!multilinecomment && line[i] == '/' && line[i + 1] == '/')
            {
                printf("%d: %s", line_number, line + i);
                break; 
            }
            else if (!multilinecomment && line[i] == '/' && line[i + 1] == '*')
            {
                multilinecomment = 1;
                printf("%d: %c%c", line_number, line[i], line[i + 1]);
                i++; 
            }

            else if (multilinecomment && line[i] == '*' && line[i + 1] == '/')
            {
                multilinecomment = 0;
                printf("%c%c\n", line[i], line[i + 1]);
                i++; 
            }
            else if (multilinecomment)
            {
                printf("%c", line[i]);
            }
        }
    }


    if (multilinecomment)
    {
        printf("Error: Unclosed multiline comment\n");
    }

    fclose(file);
}

int main()
{
    const char *filename = "test_code.c";
    find_comments(filename);
    return 0;
}
