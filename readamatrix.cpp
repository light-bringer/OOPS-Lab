#include<iostream>

using namespace std;

int **unknown(int r, int c);

main()
{
    int **a;
    int r, c;
    cout<<"enter the row of the matrix==";
    cin>>r;
    cout<<"enter the column of the matrix==";
    cin>>c;
    a=unknown(r,c);
}

int **unknownR(int r, int c)
{
    int **p;
    p=new int*[c];
    for(int i=0; i<r; i++)
    {
        *(p+i)=new int[c];
        for(int j=0; j<c; j++)
        {
            cout<<"\nEnter value";
            cin>>p[i][j];
        }
    }

    return p;

}

int **unknownC(int r, int c)
{
    int **p;
    p=new int*[r];
    for(int i=0; i<r; i++)
    {
        *(p+i)=new int[r];
        for(int j=0; j<c; j++)
        {
            cout<<"enter value";
            cin>>p[i][j];
        }
    }

    return p;

}


