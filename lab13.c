#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CHUNK 16

// 1

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Nu sunt destule argumente");
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int sum = 0;
    sum = a + b;
    printf("%d", sum);
    return 0;
}



// 2

int main(int argc, char **argv)
{
    if(argc < 3 && argc > 51)
    {
        printf("Nu sunt destule argumente");
        return 1;
    }

    int s = 0;
    for(int i = 1; i < argc; i++) {
        int k = atoi(argv[i]);
        s = s + k;
    }

    printf("%d", s);
    return 0;
}


// 3

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Nu sunt destule");
        return 1;
    }

    char *line = NULL;
    int ch = 0;
    int i = 0;
    uint32_t s = 0;
    int current_size = 0;
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");
    while (ch != EOF)
    {

        while ((ch = fgetc(fin)) != EOF)
        {
            {
                if (i == current_size)
                {
                    current_size = current_size + CHUNK;
                    line = realloc(line, current_size * sizeof(char));
                }
                if (ch != '\n')
                {
                    *(line + i++) = ch;
                }
                else
                {
                    break;
                }
            }

            if (line != NULL)
            {
                if (i == current_size)
                {
                    current_size++;
                    line = realloc(line, current_size * sizeof(char));
                }
                *(line + i) = 0;
            }
        }
        fprintf(fout, "---%s----\n", line);

        for (int i = 0; i < strlen(line); i++)
        {
            int k = line[i];
            s = s + k;
        }
    }
    fprintf(fout, "%d", s);

    fclose(fin);
    fclose(fout);
    return 0;
}
