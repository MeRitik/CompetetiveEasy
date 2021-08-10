#include<iostream>
using namespace std;

int lowerBound(int arr[], int element,int n)
{
    int low = 0, high = n-1;

    while(high-low>1)
    {
        int mid = (high+low)/2;

        if(arr[mid] < element)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }

    if(arr[low] >= element)return low;
    if(arr[high] >= element)return high;

    return -1;
}

int binarySearch(int arr[], int el, int low, int high)
{
    while(high-low>1) {
        int mid = (high+low)/2;

        if(arr[mid] == el)return mid;
        else if(arr[mid] < el) return binarySearch(arr, el, mid+1, high);
        else return binarySearch(arr, el, low, mid);
    }
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif
    int arr[6] = {2,3,4,6,7,8};
    cout << binarySearch(arr, 8, 0, 6) << endl;
    
    return 0;
}