#include <stdio.h>
#include <unistd.h>

#define STDOUT 1
#define EOF (-1)

int puts(const char *s)
{
    if (s == NULL)
    {
        return EOF;
    }

    // aflu lungimea sirului
    char *p = (char *)s;
    int len = 0;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    // scriu sirul in stdout
    if (write(STDOUT, s, len) != len)
    {
        return EOF;
    }

    //daca am reusit sa scriu sirul, scriu si un newline
    char newline = '\n';
    if (write(STDOUT, &newline, 1) != 1)
    {
        return EOF;
    }

    // returnez numarul de caractere scrise + 1 pentru newline
    return len + 1;
}
