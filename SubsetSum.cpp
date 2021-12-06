#include<bits/stdc++.h>
using namespace std;

void SubsetSum(int ind, int arr[], vector<int> &v, int k, int sum)
{
	if(ind == 3){
		if(sum % k == 0){

		//for vector without element
		if(v.size() == 0)return;
		for(auto it : v){
			cout << it << ' ';
		}
		cout << endl;
	}
		return;
	}

	sum += arr[ind];
	v.push_back(arr[ind]);
	SubsetSum(ind+1, arr, v, k, sum);

	//
	sum -= arr[ind];
	v.pop_back();
	SubsetSum(ind+1, arr, v, k, sum);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int arr[3] = {1, 2, 3};
    int k = 3;
    vector<int> v;
    SubsetSum(0, arr,v , k, 0);






    return 0;
}
