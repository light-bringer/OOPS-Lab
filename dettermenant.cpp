#include<iostream>
#include<malloc.h>
#include<math.h>

using namespace std;

void accept(double a[][20], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"\nENTER VALUE FOR A[["<<i+1<<"]][["<<j<<"]]";
            cin>>a[i][j];
        }
    }
}


void display(double a[][20], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<"\t\t";
        cout<<endl;
    }
}


double Determinant(double **a,int n)
{
    int i,j,j1,j2;
    double det = 0;
    double **m = NULL;

    if (n < 1)
        cout<<"\nERRORRRRRRRRR!!!!!!!!!!";
    else if (n == 1)
        det = a[0][0] ;
    else if (n == 2)
        det = a[0][0] * a[1][1] - a[1][0] * a[0][1] ;
    else
    {
        det = 0 ;
        for (j1 = 0 ; j1 < n ; j1++)
            {
                m = (double **) malloc((n-1)* sizeof(double *)) ;
                for (i = 0 ; i < n-1 ; i++)
                    m[i] = (double *) malloc((n-1)* sizeof(double));
                    for (i = 1 ; i < n ; i++)
                    {
                        j2 = 0 ;
                        for (j = 0 ; j < n ; j++)
                        {
                        if (j == j1)
                            continue ;
                        m[i-1][j2] = a[i][j] ;
                        j2++ ;
                        }
                    }

                det += pow(-1.0,1.0 + j1 + 1.0) * a[0][j1] * Determinant(m,n-1);
                for (i = 0 ; i < n-1 ; i++) free(m[i]);
                free(m);
        }
    }
    return(det);
}


main()
{
    double det=0;
    double ar[20][20], n=0;
    double **a=NULL;
    **a=ar[0][0];
    cout<<"\nENTER THE VALUE OF THE SIZE OF THE MATRIX , n X n - ";
    cin>>n;
    accept(ar,n);
    display(ar,n);
    det=Determinant(a,n);
    cout<<"\n THE DETERMINANT OF THE MATRIX is - "<<det;

}
