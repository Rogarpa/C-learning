#include <stdio.h>
    int bitcountImproved(unsigned x);
    unsigned toBinary(unsigned int i);

int main()
{   
    unsigned i = 0776;
    printf("%d\n", toBinary(i));
    printf("%d\n", (bitcountImproved(i)));
}

/* bitcount:  count 1 bits in x */
    int bitcount(unsigned x)
    {
        int b;
        for (b = 0; x != 0; x >>= 1)
            if (x & 01)
                b++;
        return b;
        
    }

/* bitcount: count 1 bits in x with observation x &= (x-1) deletes rightmost bit*/
    int bitcountImproved(unsigned x)
    {
        int b;
        for (b = 0; x != 0; b++)
            x &= (x-1);
        return b;
        
    }
    unsigned toBinary(unsigned int i){
        int base = 1;
        int binary = 0;
        while(i != 0){
            if (i%2 == 1){
                binary += base;
            }
            
            i = i>>1;
            base *= 10;
        }
        return binary;
    }