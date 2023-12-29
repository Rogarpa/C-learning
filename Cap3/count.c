#include <stdio.h>
#define ARRAY_SIZE 5
int countDigits(void);
int escape(char s[],char t[]);
int unescape(char s[],char t[]);
int main()  
{
    char input[] = {
                    '\t',
                    '\t',
                    'a',
                    '\0'
                    };
    
    char output[3*ARRAY_SIZE];
    output[(3*ARRAY_SIZE)-1] = '\0';

    escape(output, input);
    
    int i;
    printf("escape:\n");
    for(i = 0; i< 3*ARRAY_SIZE; ++i){
        printf("%c", output[i]);
    }
    printf("\n");
    unescape(input, output);
    
    printf("unescape:\n");
    for( i = 0; i< ARRAY_SIZE; ++i){
        printf("%c", input[i]);
    }
    printf("\n");

}
/* count digits, white space, others */
int countDigits(void){
    int c, i, nwhite, nother, ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ndigit[c-'0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);
    return 0;    
}
int escape(char s[],char t[]){
    char c;
    int i, j;
    i = 0;
    j = 0;
    while( (c = t[i]) != '\0'){
        switch (c){
            case '\n':
                s[j++] = '\\';
                if(s[j] != '\0')
                    s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                if(s[j] != '\0')
                    s[j] = 't';
                break;
            default:
                s[j] = c;
                break;
        }
        ++i;
        ++j;
    }
    s[j] = '\0';
    
}

int unescape(char s[],char t[]){
    char c;
    int i, j;
    i = 0;
    j = 0;
    while( (c = t[i]) != '\0'){
        if(c == '\\'){
            if((c = t[++i]) == '\0'){
                break;
            }

            switch (c){
                case 'n':
                    s[j] = '\n';
                    break;
                case 't':
                    s[j] = '\t';
                    break;
                default:
                    s[j] = c;
                    break;
            }
        }else{
            s[j] = c;
        }
        ++i;
        ++j;
    }
}