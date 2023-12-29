#include <stdio.h>
#include <string.h>


    unsigned int setbits(unsigned x, int p, int n, unsigned y);
    unsigned getbits(unsigned x, int p, int n);
    unsigned toBinary(unsigned int i);
    unsigned int invert(unsigned x, int p, int n);
    unsigned int rightrot(unsigned x, int n);
    unsigned int rotate(unsigned x, int n);


int main(){
    int i = 47;
    int ii = 58;
    unsigned j = 0;
    printf("i = %u\n",toBinary(i));
    printf("ii = %u\n",toBinary(ii));
    j = setbits(i, 2, 3, ii);
    printf("setbits i and ii p2 n3 = %u\n",toBinary(j));
    j = invert(ii, 2, 3);
    printf("invert ii p2 n3= %u\n",toBinary(j));
    j = rightrot(i,3);
    printf("rotate ii n3= %u\n",toBinary(j));
    
}

/* getbits:  get n bits from position p */
   unsigned getbits(unsigned x, int p, int n)
   {
       return (x >> (p+1-n)) & ~(~0 << n);
   }

    unsigned int setbits(unsigned x, int p, int n, unsigned y){
        unsigned maskOfZerosInRange = ((~0 << p+1) | ~(~0 << (p+1-n)));
        unsigned xZerosInRange = x & maskOfZerosInRange;
        unsigned yRangePositioned = ((getbits(y, p, n)<<(p+1-n)));
        return xZerosInRange | yRangePositioned;
    }
    
    unsigned int invert(unsigned x, int p, int n){
        return setbits(x, p, n, ~x);
    }
    unsigned int rightrot(unsigned x, int n){
        int rotatedx = rotate(getbits(x, 0, n), n);
        return setbits(x, 0, n, rotatedx);
    }
    unsigned int rotate(unsigned x, int n){
        int index = 0;
        unsigned int bit = 0;
        unsigned int rotated = 0;
        unsigned int adder = 1<<n-1;
        while(n > 0){
            bit = x&1;
            if(bit == 1){
                rotated = rotated | adder;
            }
            x = x >> 1;
            adder = adder >> 1;
            --n;
        }
        return rotated;
        
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