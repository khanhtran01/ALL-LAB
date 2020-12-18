#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos = left + (x-arr[left])*(right-left)/(arr[right] - arr[left]);
    if (arr[pos] < arr[left] || arr[pos] > arr[right]) return -1;
    if (x > arr[pos])
    {
        cout <<"We traverse on index: "<<pos<<'\n';
        return interpolationSearch(arr,pos+1,right,x);
    }
    else if ( x < arr[pos])
    {
        cout <<"We traverse on index: "<<pos<<'\n';
        return interpolationSearch(arr,left,pos-1,x);
    }
    cout <<"We traverse on index: "<<pos<<'\n';
    return pos;
}

int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
int n = sizeof(arr) / sizeof(arr[0]);
int x = 8;
int result = interpolationSearch(arr, 0, n - 1, x);
(result == -1) ? cout << "Element is not present in array"
               : cout << "Element is present at index " << result;
}