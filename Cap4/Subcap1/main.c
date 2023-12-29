#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */


int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindexrightmost(char source[], char searchfor[]);
char pattern[] = "ould";   /* pattern to search for */
/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;
    int indexfound = 0;
    while (getLine(line, MAXLINE) > 0)
        if ((indexfound = strindexrightmost(line, pattern)) >= 0) {
            printf("%s", line);
            printf(", index found = %d", indexfound);
            found++;
        }
    return found;
}

