#include <stdio.h>
   int lower(int c);
int main(){
    putchar(lower('A'));
}
/* lower:  convert c to lower case; ASCII only */
   int lower(int c)
   {
       return ((c >= 'A' && c <= 'Z')? c + 'a' - 'A' : c);
   }