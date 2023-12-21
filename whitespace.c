#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    char c;
    int m = 0, n = 0;
    while (fp)
    {
        c = getc(fp);
        if (c == EOF)
            break;
        if (c == ' ')
            m = m + 1;
        if (c == '\n')
            n = n + 1;
    }
    fclose(fp);
    printf("Number of white spces:%d \n", m);
    printf("Number of newline charcters:%d\n ", n);
    return 0;
}
