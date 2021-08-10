#include<iostream>
#include<vector>
using namespace std;

vector<int> DistinctElementsII(int arr[], int n)
{
	vector<int> ans;
	int mask = 0;

	//Mask: Xor of all nums
	for(int i = 0; i < n; i++){
		mask ^= arr[i];
	}
	
	int result = mask;
    mask = (mask & ~(mask-1));

    int a = 0;
    //Check if & is set
    for(int i = 0; i < n; i++){
    	if(mask&(arr[i])){
    		a ^= arr[i];
    	}
    }
    
    int b = a^result;
    ans.push_back(min(a, b));
    ans.push_back(max(a,b));

    return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
	#endif
	
	int n;
	cin>>n;

	int arr[n];

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	vector<int> vc = DistinctElementsII(arr, n);

	for(auto x : vc){
		cout << x << ' ';
	}

	

	return 0;
}
