#include <stdio.h>
    #define MAXLINE 1000   /* maximum input line length */
    #define MAXLINES 1000   /* maximum input lines buffered */
    int getLine(char line[], int maxline);
    void copy(char to[], char from[]);
    void reverse(char toReverse[], int lim);
    /* print the longest input line */
    main()
    {
        int longerLineIndex;
        int len;            /* current line length */
        int max;            /* maximum length seen so far */
        char line[MAXLINE];    /* current input line */
        char longerLine[MAXLINES][MAXLINE]; /* longest line saved here */


        longerLineIndex = 0;
        while ((len = getLine(line, MAXLINE)) > 0){
            if (longerLineIndex  < MAXLINES) {
                reverse(line, MAXLINE);
                copy(longerLine[longerLineIndex], line);
                ++longerLineIndex;
            }
        }
        
        for(longerLineIndex = 0; longerLineIndex <  MAXLINES-1; ++longerLineIndex){
            printf("%s", longerLine[longerLineIndex]);
        }
        
        return 0;
    }
    /* getLine:  read a line into s, return length  */
    int getLine(char s[],int lim)
    {
        int c, i;
        for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
            s[i] = c;
        if (c == '\n') {
            s[i] = c;
            ++i;
        }
        s[i] = '\0';
        return i;
    }

    /* copy:  copy 'from' into 'to'; assume to is big enough */
    void copy(char to[], char from[])
    {
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
            ++i;
    }
    void reverse(char toReverse[], int lim)
    {
        int length, swapIndex;
        length = 0;
        char swap;

        while((toReverse[length] != '\0') && (toReverse[length] != '\n') && (length < (lim-1))){
            ++length;
        }
        --length;

        int middle = length/2;
        for(swapIndex = 0; swapIndex < middle; ++swapIndex){
            swap = toReverse[swapIndex];
            toReverse[swapIndex] = toReverse[length-swapIndex];
            toReverse[length-swapIndex] = swap;
        }
    }