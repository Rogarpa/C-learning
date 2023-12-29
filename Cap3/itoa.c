#include <stdio.h>
#include <string.h>
   void itoa(int n, char s[]);
   void itoaForNegativeLimit(int n, char s[]);
   void itoaWithPadding(int n, char s[], int padding);
   void reverse(char s[]);
int main(){
    char s[11];
    itoaWithPadding(1, s, 5);
    printf("%s", s);
}
 /* itoa:  convert n to characters in s */
    void itoa(int n, char s[])
    {
        int i, sign;
        if ((sign = n) < 0)  /* record sign */
            n = -n;          /* make n positive */
        i = 0;
        do {      /* generate digits in reverse order */
            s[i++] = n % 10 + '0';  /* get next digit */
        } while ((n /= 10) > 0);    /* delete it */
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
    /* itoa:  convert n to characters in s included -(2^(wordsize-1))*/
   void itoaForNegativeLimit(int n, char s[])
   {
       int i, sign;
       
       sign = n < 0? -1: 1;
       i = 0;
       do {      /* generate digits in reverse order */
           s[i++] = (sign*(n % 10)) + '0';  /* get next digit */
       } while ((n /= 10) != 0);    /* delete it */
       if (sign < 0)
           s[i++] = '-';
       s[i] = '\0';
       reverse(s);
   }
    void itoaWithPadding(int n, char s[], int padding)
    {
        int i, sign;
        
        sign = n < 0? -1: 1;
        i = 0;
        do {      /* generate digits in reverse order */
            s[i++] = (sign*(n % 10)) + '0';  /* get next digit */
        } while ((n /= 10) != 0);    /* delete it */
        if (sign < 0)
            s[i++] = '-';
        for(; padding > 0; --padding){
            s[i++] = '0';
        }
        s[i] = '\0';
        reverse(s);
    }
   /* reverse:  reverse string s in place */
   void reverse(char s[])
   {
       int c, i, j;
       for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
           c = s[i];
           s[i] = s[j];
           s[j] = c;
       }
   }