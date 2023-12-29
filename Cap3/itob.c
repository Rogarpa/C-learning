#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    void reverse(char s[]);
    void itob(int n, char s[], int b);
    char getNumericalSystemChar(int n);


int main(){
    char s[11];
    itob(155, s, 16);
    printf("%s", s);
}
    void itob(int n, char s[], int b){
        int i, sign;
        char digit;
        div_t divresult;
        
        sign = n < 0? -1: 1;
        i = 0;
        do {      /* generate digits in reverse order */
            divresult = div (n,b);
            n = divresult.quot;
            digit = getNumericalSystemChar(sign*(divresult.rem));
            s[i++] = digit;  /* get next digit */
        } while (n != 0);    /* delete it */
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
    /*Only for ascii and continuos number and alphabet encodings*/
    char getNumericalSystemChar(int n){
        if((0 <= n) && (n <= 9)){
            return n +'0';
        }else if((10 <= n) && (n <= 35)){
            return (n%10) + 'A';
        }
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