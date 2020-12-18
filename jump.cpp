#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int jumpspace = sqrt(n);
    int i = 0;
    while (arr[i] < x && i < n)
    {
        cout << i << " ";
        i += jumpspace;
        if (i < n)
        {
            if (arr[i] > x)
                cout << i << " ";
        }
        else if (i > n)
            break;
    }
    if (arr[i] != x)
    {
        i -= jumpspace;
        i++;
    }
    int savejump = i + jumpspace;
    for (; i < savejump - 1; i++)
    {
        cout << i << " ";
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{

    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 144;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1)
    {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else
    {
        cout << "\n"
             << x << " is not in array!";
    }
}