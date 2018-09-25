#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int top=-1;

char Stack[100];

void push(const char);
const char pop();
void infix_to_postfix(const char *);


main( )
{
    char Infix_expression[100];
    cout<<"\n\n Enter the Infix Expression : ";
    cin.getline(Infix_expression,80);
    infix_to_postfix(Infix_expression);
    getch( );

}


void push(const char Symbol)
{
    if(top==99)
    cout<<"Error : Stack is full."<<endl;
    else
    {
        top++;
        Stack[top]=Symbol;
    }
}


const char pop()
{
    char Symbol=NULL;
    if(top==-1)
      cout<<"Error : Stack is empty."<<endl;
    else
    {
        Symbol=Stack[top];
        Stack[top]=NULL;
        top--;
    }

    return Symbol;
}



void infix_to_postfix(const char *Infix)
{
    char Infix_expression[100];
    char Postfix_expression[100];
    strcpy(Infix_expression,"(");
    strcat(Infix_expression,Infix);
    strcat(Infix_expression,")");
    char Symbol[5];
    char Temp[5];
    for(int count=0; count<strlen(Infix_expression); count++)
    {
        Symbol[0]=Infix_expression[count];
        if(Symbol[0]=='(')
                push(Symbol[0]);
        else if(Symbol[0]==')')
        {
            Symbol[0]=pop();
            while(Symbol[0]!='(')
            {
             strcat(Postfix_expression,Symbol);
             Symbol[0]=pop( );
            }
        }
        else if(Symbol[0]=='^' || Symbol[0]=='*' || Symbol[0]=='/'|| Symbol[0]=='+' || Symbol[0]=='-')
        {
            if(Symbol[0]=='*' || Symbol[0]=='/')
                {
                    Temp[0]=pop();
                    while(Temp[0]=='^' || Temp[0]=='*' || Temp[0]=='/')
                    {
                        strcat(Postfix_expression,Temp);
                        Temp[0]=pop( );
                    }
                    push(Temp[0]);
                }
            else if(Symbol[0]=='+' || Symbol[0]=='-')
            {
                Temp[0]=pop( );
                while(Temp[0]!='(')
                {
                    strcat(Postfix_expression,Temp);
                    Temp[0]=pop();
                }
                push(Temp[0]);
            }
            push(Symbol[0]);
        }

         else
            strcat(Postfix_expression,Symbol);
      }
      cout<<"\n\n Postfix Expression : "<<Postfix_expression<<endl;
}
