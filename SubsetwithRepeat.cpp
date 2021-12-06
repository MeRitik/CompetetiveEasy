#include<bits/stdc++.h>
using namespace std;

void Subsets(int arr[], int n, int ind, vector<int> v, int sum)
{
	//Base case
	if(ind == n){
		if(v.size() == 0)return;
		if(sum == 0){
			for(auto it : v){
				cout << it << ' ';
			}cout << endl;
		}
		return;
	}

	if(sum >= arr[ind]){
		sum -= arr[ind];
		v.push_back(arr[ind]);
		Subsets(arr, n, ind, v, sum);
		sum += arr[ind];
		v.pop_back();
		//Subsets(arr, n, ind, v, sum);
	}

	Subsets(arr, n, ind+1, v, sum);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int n, k;
    cin>>n>>k;
	int arr[n];
    for(auto &it : arr){
    	cin>>it;
    }
    vector<int> v;
    Subsets(arr, n, 0, v, k);

    return 0;
}
