#include <stdio.h>
#define COLSPACING 15
#define TABSPACES 4
#define IN 1
#define OUT 0
    /* count lines in input */
    main()
    {
        int charCounter, spaces, insideBlank, tabs;
        char c;
        charCounter = 0;
        spaces = 0;
        insideBlank = 0;
        tabs = 0;
        while ((c = getchar()) != EOF){
            if(c == ' '){
                insideBlank = IN;
                ++spaces;
            }else if(c == '\t'){
                insideBlank = IN;
                charCounter += TABSPACES;
                putchar('\t');
            }else{
                
                if(insideBlank == IN){
                    insideBlank = OUT;
                    spaces += (COLSPACING - (charCounter % COLSPACING));
                    tabs = spaces/TABSPACES;
                    spaces = spaces%TABSPACES;
                    for(; tabs > 0; --tabs){
                        putchar('\t');
                    }
                    for(; spaces > 0; --spaces){
                        putchar(' ');
                    }
                    charCounter = 0;
                }

                ++charCounter;
                putchar(c);
            }
            
            if (c == '\n'){
                charCounter = 0;
                putchar('\n');
            }
        }
        
        for(int i = 0; i<30; ++i){
            printf("%d", i);
        }



    }

