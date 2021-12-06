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

int Solve(int arr[], int n, int k) {
	if(n == 0)return 0;

	int i = 0, j = 0, sum = 0;
	int minLen = INT_MAX;

	while(i <= j and j < n) {
		while(j < n and sum	<= k) {
			sum += arr[j++];
		}

		while(i<j and sum > k) {
			sum = sum - arr[i];
			minLen = min(minLen, j-i);
			i++;
		}
	}
	return minLen;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif
	
    int T;
    cin>>T;
    while(T--) {
       
    	int n, k;
    	cin>>n>>k;
    	int arr[n];
    	for(auto &it: arr) {
    		cin >> it;
    	}
	   	cout << Solve(arr, n, k) << endl;
	}

    return 0;
}