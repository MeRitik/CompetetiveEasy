#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

void DutchNationalFlagAlgo(int arr[], int a, int b, int n) {
	int low = 0, mid = 0, high = n-1;

	while(mid<=high) {
		if(arr[mid] < a){
			swap(arr[mid], arr[low]);
			mid++;
			low++;
		}
		else if(arr[mid] >= a && arr[mid] <= b) {
			mid++;
		}
		else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    // srand(time(NULL));
    int n = rand() % 10 + ;
    int arr[n];
    for(int i = 0; i < n; i++)
    	arr[i] = rand() % 10 + 1;

    int a = rand() % 3 + 1;
    int b = rand() % 8 + 1;

    // int n;
    // cin>>n;
    // int arr[n];
    // for(auto &it: arr) {
    // 	cin>>it;
    // }
    // int a, b;
    // cin>>a>>b;
    for(auto it: arr)
    	cout << it << ' ';

    cout << endl;
    DutchNationalFlagAlgo(arr, a, b, n);
    for(auto it: arr)
    	cout << it << ' ';

    
    

    return 0;
}