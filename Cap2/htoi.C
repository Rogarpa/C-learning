#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int htoi(char s[], int lim);
int isHexChar(char c);

int main()
{   
}

int htoi(char s[], int lim){
    int charToInt = 0;
    int conversion = 0;
    char c1;
    int begin = TRUE;
    int positionMultiplicator = 1;
    int i = 0;
    while((i < lim-1) && (s[i] != '\0')){
        if(begin == TRUE){
            begin = FALSE;
            if((s[i] == '0') && (tolower(s[i+1]) == 'x'))
                i += 2;
                continue;
        }
        if((charToInt = isHexChar(s[i])) == -1){
            return -1;
        }
        conversion += positionMultiplicator*charToInt;
        positionMultiplicator *= 16;
        ++i;
    }
    return conversion;

}
int isHexChar(char c){
    char alphabet[] = {
                        '0',
                        '1',
                        '2',
                        '3',
                        '4',
                        '5',
                        '6',
                        '7',
                        '8',
                        '9',
                        'a',
                        'b',
                        'c',
                        'd',
                        'e',
                        'f'
                    };
    for(int i = 0; i <= 15; ++i){
        if(alphabet[i] == c)
            return i;
    }
    return -1;
}

