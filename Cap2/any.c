#include <stdio.h>
    int anyChar(char s[], int c);
    int any(char s1[], char s2[]);
    int main()
    {
        char s1[] = {
                        'b',
                        'c',
                        'a',
                        'd',
                        'e',
                        '\0'
                    };
        char s2[] = {
                        'f',
                        'g',
                        'h',
                        'i',
                        'a',
                        '\0'
                    };
        printf("%d",any(s1, s2));
        int i;
    }
    /* anyChar:  returns index of first appearance of char c into s1*/
    int anyChar(char s[], int c)
    {
        int i;
        for (i = 0; s[i] != '\0'; i++)
            if (s[i] == c)
                return i;
        s[i] = '\0';
        
        return -1;
    }
    
    
    /* any:  returns index of first appearance of any s2 char into s1*/
    int any(char s1[], char s2[])
    {
        int i, indexFound;
        i = 0;
        indexFound = 0;
        for(i=0; s2[i] != '\0'; ++i){
            indexFound = anyChar(s1, s2[i]);
            if(indexFound != -1){
                return indexFound;
            }
        }

        return -1;
    }