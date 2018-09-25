#include <iostream>
using namespace std;

int main ()
{
	int **twoDArray=NULL;
	int i, rows, columns;
    cout << "enter how many rows: ";
	cin >> rows;
	twoDArray = new int* [rows];

	for(i=0;i<rows; i++)
    {
		cout<<"how many columns in THIS --> ["<<(i+1)<<"] ROW:  ";
		cin>>columns;
		twoDArray[i]=new int[columns+1];
		twoDArray[i][0]=columns;
        for(int j=1; j<=columns; j++)
			twoDArray [i] [j] = 0;
	}

	cout << "\nOutput of members: " << endl;
	for (i=0; i<rows; i++)
		{
            for (int j=0; j<= twoDArray[i][0]; j++)
                cout<<"["<<i<<"]["<<j<<"] = "<<twoDArray[i][j]<<"\n";

		}

	for (i=0; i<rows; i++)
		delete [] twoDArray[i];
	delete [] twoDArray;

}
