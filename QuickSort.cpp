#include <random>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j, i = (low - 1);

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[j]);

    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    srand(time(NULL));
    int n = rand() % 20 + 1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    for (auto it : arr)
        cout << it << ' ';
    cout << endl;

    QuickSort(arr, 0, n - 1);
    for (auto it : arr)
        cout << it << ' ';



    return 0;
}