#define BUFSIZE 100
#include <stdio.h>
char buf;    /* buffer for ungetch */
int availableBuffer = 0;
int getuniquech(void)  /* get a (possibly pushed-back) character */
{
    if(availableBuffer > 0){
        if((buf == EOF) && (getchar() != EOF)){
            printf("getuniquech: getting EOF while input stream not ended\n");
            return;
        }
        availableBuffer = 0;
        return buf;
    }
    return getchar();
}
void ungetuniquech(int c)   /* push character back on input */
{
    if (availableBuffer > 0)
        printf("ungetuniquech: too many characters\n");
    else{
        if((c == EOF) && ((buf = getchar()) != EOF)){
            availableBuffer = 1;
            printf("ungetuniquech: ungetting EOF while input stream not ended\n");
            return;
        }
        buf = c;
        availableBuffer = 1;
    }
}
