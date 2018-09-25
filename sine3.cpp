#include <stdio.h>
#include <math.h>
// We need to output stuff, and we need the sine function

int main()
{
    // declarations
    int x;
    char y[80];
     // setting entire array to spaces
    for(x = 0; x < 79; x++)
        y[x] = ' ';
    y[79] = '\0';

    // print 20 lines, for one period (2 pi radians)
    for(x = 0; x < 20; x++)
    {
        y[39 + (int) (39 * sin(M_PI * (float) x / 10))] = '*';
        printf("%s\n", y);
        y[39 + (int) (39 * sin(M_PI * (float) x / 10))] = ' ';
    }

    // exit
    return 0;
}
