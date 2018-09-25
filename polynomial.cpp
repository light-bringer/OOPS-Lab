#include<iostream>

using namespace std;

void accept(int a[], int n);
void display(int a[], int n);


main()
{
    int n;
    cout<<"\nENTER THE HIGHEST POWER OF THE POLYNOMIAL YOU WANT TO ADD? ";
    cin>>n;
    int *a= new int [n+1];
    int *b= new int [n+1];
    int *c= new int [n+1];
    cout<<"\nFOR POLYNOMIAL 1- \n";
    accept(a, n);
    cout<<"\nFOR POLYNOMIAL 2- \n";
    accept(b, n);
    for(int i=0; i<=n; i++)
        c[i]=a[i]+b[i];

    cout<<"\nPOLYNOMIAL 1 ";
    display(a,n);
    cout<<"\nPOLYNOMIAL 2 ";
    display(b,n);
    cout<<"\n SUM of the Polynomials = ";
    display(c,n);


}


void accept(int a[], int n)
{
    for(int i=0; i<=n; i++)
    {
        cout<<"\nEnter value for power "<<i;
        cin>>a[i];
    }
}


void display(int a[], int n)
{
    cout<<endl;
    for(int i=n; i>=0; i--)
        cout<<a[i]<<"x^"<<i<<"+";
    cout<<"\b\b";
}
