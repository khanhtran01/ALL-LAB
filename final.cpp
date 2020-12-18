#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;

void printByPattern(int data[], int count) {
    
    if (count % 2 == 0)
    {
        for (int i = 0 ; i <count/2 ; i++)
        {
            cout <<data[i] + data[count-1-i];
            if (i<(count-1)/2) cout <<" ";
        }
        //cout <<"\n";
    }
    else {
        for ( int i = 0 ; i < (count-1)/2; i++)
        {
            cout <<data[i] + data[count-1-i]<<" ";
        }
        cout << data[(count-1)/2]<<'\n';
    }
    //cout<< count;
    }

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1], ifstream::in);

    int count;
    ifs >> count;

    int* data = new int[count];

    for (int i = 0; i < count && ifs.good(); ++i) {
        ifs >> data[i];
    }

    printByPattern(data, count);

    ifs.close();
    return 0;
}