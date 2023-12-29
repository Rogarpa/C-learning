#include <stdio.h>
#include <time.h>
#define ARRAY_SIZE 1000
    int binsearch(int x, int v[], int n);
    int binsearch2(int x, int v[], int n);
int main(){
    int arrayToSearch[ARRAY_SIZE];
    for(int i = 0; i<ARRAY_SIZE; ++i){
        arrayToSearch[i] = i;
    }
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    for(int i = 0; i<ARRAY_SIZE; ++i){
        binsearch(i, arrayToSearch, ARRAY_SIZE);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("binsearch() took %f seconds to execute \n", cpu_time_used);


    start = clock();

    for(int i = 0; i<ARRAY_SIZE; ++i){
        binsearch2(i, arrayToSearch, ARRAY_SIZE);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("binsearch() took %f seconds to execute \n", cpu_time_used);

}
/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    int iterations = 0;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]){
            high = mid - 1;
        }
        else if (x  > v[mid]){
            low = mid + 1;
        }          
        else    /* found match */
            return mid;
    }
    return -1;   /* no match */
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while ( low <= high && x != v[mid] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if ( x == v[mid] )
        return mid;
    else
        return -1;
}
