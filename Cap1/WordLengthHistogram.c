#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLENGTH 5
   /* count digits, white space, others */
   main()
   {
        int c, i, j;
        int state = OUT;
        int nWordLength[MAXLENGTH];
        for (i = 0; i < MAXLENGTH; ++i)
            nWordLength[i] = 0;

        int lengthCounter = 0;
        while (((c = getchar()) != EOF)){
            if (c == ' ' || c == '\n' || c == '\t'){
                state = OUT;
                ++nWordLength[lengthCounter];
            }else{
                if (state == OUT){
                    state = IN;
                    lengthCounter = 1;
                }else if(lengthCounter < MAXLENGTH){
                    lengthCounter++;
                }
            }
        }
       
       
       
        printf("HISTOGRAM");
        printf("===================================================");
        printf("===================================================");
        for (i = 0; i < MAXLENGTH; ++i){
            printf("%d: ", i);
            for(j = 0; j < nWordLength[i]; ++j){
                putchar('*');
            }
            printf("\n");
       }
   }