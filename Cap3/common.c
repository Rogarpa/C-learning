#include <stdio.h>
void commonWithGoto(int a[], int b[], int n, int m){
    int i, j;
    for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (a[i] == b[j])
                    goto found;
    /* didn't find any common element */
    found:
        /* got one: a[i] == b[j] */
        printf("founded common element");
}

void common(int a[], int b[],int n,int m){
    int i, j, found;
    found = 0;
    for (i = 0; i < n && !found; i++)
        for (j = 0; j < m && !found; j++)
            if (a[i] == b[j])
                found = 1;
    if (found)
        /* got one: a[i-1] == b[j-1] */
        printf("founded common element");
    else
        /* didn't find any common element */
        printf("has not common element");
}