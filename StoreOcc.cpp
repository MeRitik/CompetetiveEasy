#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

int storeOcc(int *arr, int i, int len, int num, int *occ, int j) {
	if(i == len)
		return j;//return count of occurences

	if(arr[i] == num) {
		occ[j++] = i;
	}
	return storeOcc(arr, i+1, len, num, occ, j);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int arr[] = {2, 3, 2, 4, 23, 34, 2, 24};
    int len = sizeof(arr)/sizeof(int);
    int occ[5] = {-1};
    cout << storeOcc(arr, 0, len, 2, occ, 0) << endl;



    return 0;
}