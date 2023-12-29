#include <stdio.h>
    /* getLine:  get line into s, return length */
    int getLine(char s[], int lim)
    {
        int c, i;
        i = 0;
        while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
            s[i++] = c;
        if (c == '\n')
            s[i++] = c;
        s[i] = '\0';
        return i;
    }