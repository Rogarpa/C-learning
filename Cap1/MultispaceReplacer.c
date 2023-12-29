 #include <stdio.h>
   /* count lines in input */
   main()
   {
       int c, nl;
       int insideBlank;
       nl = 0;
       while ((c = getchar()) != EOF){
           if(c == ' '){
                if(!insideBlank)
                    insideBlank = 1;
                    putchar(c);
            }else{
                insideBlank = 0;
                putchar(c);
            }
            
       }
        

            
   }

   