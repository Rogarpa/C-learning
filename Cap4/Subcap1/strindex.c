#include <stdio.h>

    /* strindex:  return index of t in s, -1 if none */
    int strindex(char s[], char t[])
    {
        int i, j, k;
        for (i = 0; s[i] != '\0'; i++) {
            for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
                ;
            if (k > 0 && t[k] == '\0')
                return i;
        }
        return -1;
    }
    /* strindex:  return index of rightmost ocurrence of t in s, -1 if none */
    int strindexrightmost(char s[], char t[])
    {
        int i, j, k;
        int rightmost = -1;
        for (i = 0; s[i] != '\0'; i++) {
            for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
                ;
            if (k > 0 && t[k] == '\0')
                rightmost =  i;
        }
        
        return rightmost;
    }