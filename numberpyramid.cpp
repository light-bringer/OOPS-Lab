#include<iostream>
#include<iomanip>

using namespace std;

main()
{
    int n=0,k=0;
    cout<<"ENTER THE NUMBER UPTO WHICH YOU WANT TO MAKE PYRAMID ";
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cout<<setw(n-i+1);
        for(k=1; k<=i; k++)
            cout<<k%10;
        for(k=i-1; k>0 ; k--)
            cout<<k%10;
        cout<<endl;
    }
}
