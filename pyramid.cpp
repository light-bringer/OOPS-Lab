#include<iostream>
#include<iomanip>

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
    int n=0;
    double t;
    cout<<"\nENTER THE POWER, n OF THE BINOMIAL - (1+x)^n : " ;
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cout<<setw(n-i+1);
        for(int j=0; j<=i; j++)
        {
            t=(factorial(i)/(factorial(j)*factorial(i-j)));
            cout<<t;
        }
        cout<<endl;
    }

}

