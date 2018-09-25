#include<iostream>

using namespace std;



main()
{
    int a=5, b = 10, c;
    int *p=&a, *q=&b;
    cout<<c<<p<<q;
    c=p-q;
    cout<<c;
}
