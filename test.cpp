#define MAX_LEN 200
#include<iostream>
#include<string.h>
#include<fstream>
#include<ctime>
using namespace std;

void swap(int &a,int &b)
{
  int c = a;
  a = b;
  b = c;
}
int main(int narg, char**a)
{
int x,y;
cin >> x >> y;
cout <<x << "   " << y <<'\n';
swap(x,y);
cout <<x << "   " << y <<'\n';
return 0;
}