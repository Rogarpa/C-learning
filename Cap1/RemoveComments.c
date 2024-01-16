#include <stdio.h>
#define IN 1
#define OUT 0
    /* count lines in input */
    main()
    {
        int insideOneLineComment, insideMultilineComment, preSlash, preAsterisk;
        char c;
        insideOneLineComment = insideMultilineComment = preSlash = preAsterisk = OUT;

        while ((c = getchar()) != EOF){

            if(c == '/'){
                if(preAsterisk == IN){
                    insideMultilineComment == OUT;
                    preAsterisk = OUT;
                }
                if(preSlash == IN){
                    insideOneLineComment = IN;
                    preSlash = OUT;
                }
            }else if(c == '*'){
                if(preSlash == IN){
                    insideMultilineComment = IN;
                    preSlash = OUT;
                }
            }else if(c == '\n'){
                insideOneLineComment = OUT;
            }else{
                if(preSlash == IN){
                    putchar('/');
                    preSlash = OUT;
                }
                if(preAsterisk == IN){
                    putchar('*');
                    preAsterisk = OUT;
                }
                if((insideOneLineComment == IN) || (insideMultilineComment == IN)){
                    ;
                }else{
                    putchar(c);
                }
            }
            
            if(c == '/'){
                preSlash = IN;
            }else if(c == '*'){
                preAsterisk = IN;
            }
            

        }

    }

