#include <stdio.h>
    void squeeze(char s[], int c);
    void squeeze2(char s1[], char s2[]);
    int searchChar(char c, char into[]);
    int main()
    {
        char s1[] = {
                        'a',
                        'b',
                        'c',
                        'd',
                        'e',
                        '\0'
                    };
        char s2[] = {
                        'a',
                        'b',
                        'c',
                        'd',
                        '\0'
                    };
        squeeze2(s1, s2);
        int i;
        for(i=0; s1[i] != '\0'; ++i){
            putchar(s1[i]);
            putchar('\n');
        }
    }
/* squeeze:  delete all c from s */
    void squeeze(char s[], int c)
    {
        int i, j;
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != c)
                s[j++] = s[i];
        s[j] = '\0';
    }
    /* squeeze:  delete all s2 from s1 */
    void squeeze2(char s1[], char s2[])
    {
        int i;
        for(i=0; s2[i] != '\0'; ++i){
            squeeze(s1, s2[i]);
        }
    }
    