#include<iostream>
#include<iomanip>

using namespace std;

main()
{
    int n;
    cout<<"\nENTER THE NUMBER OF ROWS - ";
    cin>>n;
    for(int i=1; i<=n; i++)
        cout<<setfill(' ')<<setw(n-i)<<""<<setfill('*')<<setw(2*i-1)<<""<<endl;

}
