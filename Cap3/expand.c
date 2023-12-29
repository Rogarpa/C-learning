#include <limits.h>
#include <stdio.h>
#define ARRAY_SIZE 10
    void expand(char s1[], char s2[]);
    int append(char begin, char end, char s[], int position);

int main() {
    char s[ARRAY_SIZE];
    expand("a-c", s);
    printf("%s", s);
}
    void expand(char s1[], char s2[]){
        // enum states = {TRAILINGMINUS = 1, FIRSTCHAR = 2, MIDDLESLASH = 3, SECONDCHAR = 4};
        enum states  {TRAILINGMINUS, FIRSTCHAR, MIDDLESLASH, SECONDCHAR};
        int i, appendingPosition;
        enum states state = TRAILINGMINUS;
        state = TRAILINGMINUS;
        char c, begin, end;

        i = 0;
        appendingPosition = 0;
        while((c = s1[i]) != '\0'){
            switch (state)
            {
                case TRAILINGMINUS:
                    if(c == '-'){
                        ;
                    }else{
                        begin = c;
                        state = FIRSTCHAR;
                    }
                    break;
                case FIRSTCHAR:
                    if(c == '-'){
                        state = MIDDLESLASH;
                    }else{
                        begin = c;
                    }
                    break;
                case MIDDLESLASH:
                    if(c == '-'){
                        ;
                    }else{
                        end = c;
                        state = SECONDCHAR;
                        appendingPosition += append(begin, end, s2, appendingPosition);
                    }
                    break;
                case SECONDCHAR:
                    if(c == '-'){
                        begin = end;
                        state = FIRSTCHAR;
                    }else{
                        begin = c;
                        state = FIRSTCHAR;
                    }
                    break;
                default:
                    break;
            }
            ++i;
        }
        s2[appendingPosition] = '\0';

    }
    int append(char begin, char end, char s[], int position){
        if(begin > end){
            return 0;
        }
        int appended = (end-begin)+1;
        for(; begin <= end; begin++, position++){
            s[position] = begin;
        }
        return appended;
    }

