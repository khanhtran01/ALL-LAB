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

void deleteAllCharacter(char str[], char key) {
    for (int i = 0; i < strlen(str);i++){
        if ( str[i] == key )
        {
            for (int j = i ; j < strlen(str) ; j++)
            {
                str[j] = str[j+1];
                
            }
        }
    }

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1], ifstream::in);

    string _str;
    getline(ifs, _str);
    char* str = (char*) malloc(sizeof(char) * (strlen(_str.c_str()) + 1));
    strcpy(str, _str.c_str());

    getline(ifs, _str);
    char key = _str.at(0);

    deleteAllCharacter(str, key);
    printf("%s", str);

    ifs.close();
    return 0;
}