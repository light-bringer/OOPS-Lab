
#include<iostream>

using namespace std;

unsigned factorial(unsigned n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}


main()
{
    int n;
    double t;
    cout<<"\nENTER THE POWER, n OF THE BINOMIAL - (1+x)^n : ";
    cin>>n;
    cout<<"term"<<"\t"<<"coefficient"<<endl;
    for(int i=0; i<=n; i++)
    {
        t=(factorial(n)/(factorial(i)*factorial(n-i)));
        cout<<i+1<<"\t\t"<<t<<endl;

    }
}
