#include<stdio.h>
#define MAX 100
char stack[MAX];
int top;
void compact(char Descomp[], char Compac[]);
void init_stack();
int push(char Elem);
int desempilha(char *Elem);
int priority(char Operator);
int arity(char Exp[], int position);
int translate_pos(char exp[], char exp_pos[]);
int main()
    {
        char Exp[MAX]; /* stores the expression read from stdin */
            char Exp_compact[MAX]; /* stores expression without spaces */
            char Exp_pos[MAX]; /* stores the expression after the translation for postfix*/
            int indicator; /* indicate if an error occurred, 0 for NO ERROR and -1 for ERROR*/
            indicator = 0;
            printf("\nType the expression: ");
            gets(Exp);
            compact(Exp, Exp_compact);
            indicator = translate_pos(Exp_compact, Exp_pos);
            puts(Exp_pos);
            return indicator;
        }
/* compact function delete spaces within the expression read from stdin */
void compact(char Descomp[], char Compac[])
        {
            int i;
            int j;
            i = 0;
            j = 0;
            while(Descomp[j] != '\0')
                {
                    if(Descomp[j] != ' ')
                        {
                            Compac[i] = Descomp[j];
                            i++;
                        }
                    j++;
                }
        }
/* initiate the stack by setting top = -1 */
void init_stack()
        {
            top = -1;
        }
/* puts the element Elem in the stack */
int push(char Elem)
        {
            if(top == MAX - 1) /* Stack is full */
                return -1;
            top++;
            stack[top] = Elem;
            return 0;
        }
/* remove the element in stack[top] and puts it in &Elem*/
int pop(char *Elem)
        {
            if(top == -1) /* stack is empty */
                return -1;
            *Elem = stack[top];
            top--;
            return 0;
        }
/* Return the priority of an operator */
int priority(char Operator)
        {
            switch(Operator)
                {
                    case '+': return 1;
                    case '-': return 1;
                    case '*': return 2;
                    case '/': return 2;
                    case '^': return 3;
                    case '(': return 4;
                    case ')': return 5;
                    default : return 0;
                }
        }
/* returns the arity of CONSTANTS + - * / and ^, for ( an ) is merely symbolic */
int arity(char Exp[], int position)
        {
            if(priority(Exp[position]) == 1)
                {
                    if( (position == 0) || ( (priority(Exp[position - 1]) >= 1) && (priority(Exp[position - 1]) <= 3) ))
                        return 1;
                    else
                        return 2;
                }
            else if( (priority(Exp[position]) > 1) && (priority(Exp[position]) <= 4))
                return 2;
            else
                return priority(Exp[position]);
        }
/* reads an infix expression and returns postfix expression */
int translate_pos(char exp[], char exp_pos[])
        {
            int i;
            int j;
            int ind;
            char trash;
            i = 0;
            j = 0;
            ind = 0;
            trash = ' ';
                    init_stack();
            while(exp[i]!= '\0')
                {
                    if(arity(exp, i) == 0)
                        {
                            exp_pos[j] = exp[i];
                            j++;
                        }
                    if(arity(exp, i) == 1)
                        {
                            switch(exp[i])
                                {
                                    case '-':
                                        {
                                            exp_pos[j] = exp_pos[i];
                                            j++;
                                        }
                                    case '+': trash = exp_pos[i];
                                }
                        }
                    if(arity(exp, i) == 2)
                        {
                            while((top != -1) && (priority(stack[top]) <= priority(exp[i])))
                                {
                                    ind = pop(&exp_pos[j]);
                                    j++;
                                }
                            ind = push(exp[i]);
                        }
                    if(priority(exp[i]) == 4)
                        {
                            ind = push(exp[i]);
                        }
                    if(priority(exp[i]) == 5)
                        {
                            while( (top != -1) && (stack[top] != '('))
                                {
                                    ind = pop(&exp_pos[j]);
                                    j++;
                                }
                            if(stack[top] == '(')
                                ind = pop(&trash);
                        }
                    i++;
                }
            while(top != -1)
                {
                    ind = pop(&exp_pos[j]);
                    j++;
                }
            return ind;

    }
