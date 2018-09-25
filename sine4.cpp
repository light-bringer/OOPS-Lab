
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>

using namespace std;

int main( )
{

// Variables //

float fx;
double x;

initwindow( 800 , 600 , "WinBGIm" );

// AXES //
line (10,0,10,600);
line (0,300,800,300);

for (int i=1;i<10000;i++)
{
x=(i + 10); //Moves the graph to the right place
fx = sin(x*3.14/180) + 300; //+300 does the same
putpixel (x,fx,12);
}
cin.get();
closegraph( );

return( 0 );
}
