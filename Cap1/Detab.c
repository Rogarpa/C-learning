#include <stdio.h>
#define COLSPACING 15
#define TABSPACES 4
#define IN 1
#define OUT 0
    /* count lines in input */
    main()
    {
        int charCounter, spaces, tabSpacesIterator, insideTabSequence;
        char c;
        charCounter = 0;
        spaces = 0;
        tabSpacesIterator = 0;
        insideTabSequence = 0;
        while ((c = getchar()) != EOF){
            if(c == '\t'){
                insideTabSequence = IN;
                tabSpacesIterator = 0;
                for(; tabSpacesIterator < TABSPACES; ++tabSpacesIterator){
                    putchar(' ');
                }
                charCounter += TABSPACES;
            }else{
                
                if(insideTabSequence == IN){
                    insideTabSequence = OUT;
                    spaces = COLSPACING - (charCounter % COLSPACING);
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



    }

