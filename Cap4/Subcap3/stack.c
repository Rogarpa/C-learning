#include <stdio.h>
#define MAXVAL  100  /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
double peek(void)
{
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
void printPeek(void)
{
    if (sp > 0)
        printf("%f", val[sp-1]);
    else {
        printf("error: stack empty\n");
    }
}
void duplicate(void)
{
    if (sp < MAXVAL)
        val[sp++] = peek();
    else
        printf("error: stack full, can't duplicate\n");
}
void swap(void)
{
    if(sp > 1){
        printf("error: stack size is not enough\n");
    }

    double pop1, pop2;
    pop1 = pop();
    pop2 = pop();
    push(pop1);
    push(pop2);
}
void clear(void)
{
    int sp = 0;
}