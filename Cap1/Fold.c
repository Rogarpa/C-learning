#include <stdio.h>
#define COLSPACING 15
#define TABSPACES 4
#define CUTCOLUMN 5
#define IN 1
#define OUT 0
    /* count lines in input */
    main()
    {
        int charCounter, sublineCounter, lineBreak, first;
        char subline[CUTCOLUMN];
        char c;
        charCounter = 0;
        sublineCounter = 0;
        lineBreak = 0;
        first = 1;
        while ((c = getchar()) != '\n'){
            subline[sublineCounter] = c;
            if((sublineCounter == (CUTCOLUMN-1)) && (first == 0)){
                lineBreak = 0;
                for(sublineCounter = CUTCOLUMN-1; sublineCounter >= 0; --sublineCounter){
                    if((subline[sublineCounter] == ' ') || (subline[sublineCounter] == '\t')){
                        lineBreak = sublineCounter;
                        break;
                    }
                }
                
                if (sublineCounter == -1) lineBreak = CUTCOLUMN;
                for(sublineCounter = 0; sublineCounter < lineBreak; ++sublineCounter){
                    putchar(subline[sublineCounter]);
                }
                putchar('\n');
                
                lineBreak = (lineBreak+1);
                for(sublineCounter = 0; lineBreak + sublineCounter < CUTCOLUMN; ++sublineCounter){
                    subline[sublineCounter] = subline[lineBreak + sublineCounter];
                }
                
            }else{
                sublineCounter = (sublineCounter + 1) % CUTCOLUMN;
                if(first) first = 0;
            }

                

            

            if (c == '\n'){
                putchar(c);
            }
        }
            for(int residual = 0; residual < sublineCounter; ++residual){
                    putchar(subline[residual]);
                }
            putchar('\n');

    }

