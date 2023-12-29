#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <math.h>  /* for  sin, exp and pow */
#include <ctype.h>
#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define ALPHABET_SIZE  26  /* maximum depth of val stack */
double memmory[ALPHABET_SIZE]; /*for calculator variables*/
int getop(char []);
void push(double);
double pop(void);
double peek(void);
/* reverse Polish calculator */

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'x':
                push(exp(pop()));
                break;
            case 'p':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '\n':
                memmory['l' - 'a'] = peek();
                printf("\t%.8g\n", pop());
                break;
            default:
                if(isalpha(type) && islower(type)){
                    push(memmory[type-'a']);
                    break;
                }

                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}