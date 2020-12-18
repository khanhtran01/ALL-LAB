#include <iostream>
#include <algorithm>

using namespace std;

int minWaitingTime(int n, int arrvalTime[], int completeTime[])
{
    int sub[n];
    for (int i = 0; i < n; i++)
    {
        sub[i] = completeTime[i] - arrvalTime[i];
    }
    make_heap(&sub[0], &sub[n]);
    sort_heap(&sub[0], &sub[n]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sub[i] == completeTime[j] - arrvalTime[j])
            {
                swap(completeTime[j], completeTime[i]);
                swap(arrvalTime[j], arrvalTime[i]);
                break;
            }
        }
    }
    int sum = 0;
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        sum += completeTime[i];
        if (sum - arrvalTime[i] >= 0)
            min += sum - arrvalTime[i];
    }
    return min;
}

int main()
{

    int n = 2;
    int arrvalTime[] = {0, 2, 2, 5};
    int completeTime[] = {4, 6, 3, 4};

    cout << minWaitingTime(n, arrvalTime, completeTime);
}