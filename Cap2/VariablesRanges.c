#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
    double bytesSize(double toMeasure);
    main(){
        printf("CHAR_MIN=%d\n",CHAR_MIN);
        printf("CHAR_MAX=%d\n",CHAR_MAX);
        printf("0=%d\n",0);
        printf("UCHAR_MAX=%d\n",UCHAR_MAX);
        printf("\n");

        printf("BYTES CHAR_MIN=%lf\n",bytesSize(CHAR_MIN));
        printf("BYTES CHAR_MAX=%lf\n",bytesSize(CHAR_MAX));
        printf("BYTES 0=%lf\n",bytesSize(0));
        printf("BYTES UCHAR_MAX=%lf\n",bytesSize(UCHAR_MAX));
        printf("\n");

        printf("SHRT_MIN=%d\n", SHRT_MIN);
        printf("SHRT_MAX=%d\n", SHRT_MAX);
        printf("0=%d\n", 0);
        printf("USHRT_MAX=%d\n", USHRT_MAX);
        printf("\n");

        printf("BYTES SHRT_MIN=%lf\n", bytesSize(SHRT_MIN));
        printf("BYTES SHRT_MAX=%lf\n", bytesSize(SHRT_MAX));
        printf("BYTES 0=%lf\n", bytesSize(0));
        printf("BYTES USHRT_MAX=%lf\n", bytesSize(USHRT_MAX));
        printf("\n");


        printf("INT_MIN=%d\n", INT_MIN);
        printf("INT_MAX=%d\n", INT_MAX);
        printf("0=%d\n", 0);
        printf("UINT_MAX=%d\n", UINT_MAX);
        printf("\n");

        printf("BYTES INT_MIN=%lf\n", bytesSize(INT_MIN));
        printf("BYTES INT_MAX=%lf\n", bytesSize(INT_MAX));
        printf("BYTES 0=%lf\n", bytesSize(0));
        printf("BYTES UINT_MAX=%lf\n", bytesSize(UINT_MAX));
        printf("\n");

        printf("LONG_MIN=%ld\n", LONG_MIN);
        printf("LONG_MAX=%ld\n", LONG_MAX);
        printf("0=%d\n", 0);
        printf("ULONG_MAX=%lu\n", ULONG_MAX);
        printf("\n");

        printf("BYTES LONG_MIN=%lf\n", bytesSize(LONG_MIN));
        printf("BYTES LONG_MAX=%lf\n", bytesSize(LONG_MAX));
        printf("BYTES 0=%lf\n", bytesSize(0));
        printf("BYTES ULONG_MAX=%lf\n", bytesSize(ULONG_MAX));
        printf("\n");

    }



    double bytesSize(double toMeasure){
        return ((log10(toMeasure))/(log10(2)));
    }
