#define BUFSIZE 100
#include <stdio.h>
char buf;    /* buffer for ungetch */
int availableBuffer = 0;
int getuniquech(void)  /* get a (possibly pushed-back) character */
{
    if(availableBuffer > 0){
        availableBuffer = 0;
        return buf;
    }
    return getchar();
}
void ungetuniquech(int c)   /* push character back on input */
{
    if (availableBuffer > 0)
        printf("ungetch: too many characters\n");
    else{
        buf = c;
        availableBuffer = 1;
    }
}
