 #include <stdio.h>
   /* count lines in input */
   main()
   {
       int c, nl;
       int insideBlank;
       nl = 0;
       while ((c = getchar()) != EOF){
           if(c == '\b'){
                putchar('\\');
                putchar('b');
            }else if(c == '\t'){
                putchar('\\');
                putchar('t');
            }else if(c == '\\'){
                putchar('\\');
                putchar('\\');
            }else 
                putchar(c);
            
       }



   }

