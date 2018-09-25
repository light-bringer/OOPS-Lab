#include<fstream>
#include<iostream>
#include<string>

using namespace std;

main()
{
    fstream fob, fob1;
    int x=0;
    char c[200];
    fob.open("input.txt", ios::in);
    fob1.open("output.txt", ios::out);
    if(!fob)
        cout<<"\nFILE DOESNT EXIST!!";
    while(fob)
    {
        fob.read( c,'\n');
        if(c[0]=='{')
            x++;
        else if(c[0]=='}')
            x--;
        for(int i=1; i<=x; i++)
            fob1.put('\t');
        fob1.write(c, '\n');


    }


    fob.close();
    fob1.close();
}
