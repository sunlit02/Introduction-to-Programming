#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    int op_st[100], op_opr_size[100], op_sp = -1;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case '+':
                op_st[op_sp++] = '+';
                op_opr_size[op_sp] = size();
                break;
            case '-':
                op_st[op_sp++] = '-';
                op_opr_size[op_sp] = size();
                break;
            case '*':
                op_st[op_sp++] = '*';
                op_opr_size[op_sp] = size();
                break;
            case '/':
                op_st[op_sp++] = '/';
                op_opr_size[op_sp] = size();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;

            case NUMBER:
                push(atof(s));
                while(op_sp != -1 && size() >= 2)
                {
                    int op = op_st[op_sp--];
                    switch (op)
                    {
                    case '+':
                        push(pop() + pop());
                        break;
                    case '*':
                        push(pop()*pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case '/':
                        op2 = pop();
                        if (op2 != 0.0) push(pop() / op2);
                        else printf("error: zero divisor\n");
                        break;
                    }
                }
                break;

        default:
            printf("error: unknown command %s\n", s);
            break;        
        }
    }
    return 0;
}