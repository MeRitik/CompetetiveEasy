#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<int> DistinctWindowCount(int arr[], int n, int k)
		{
			vector<int> Counts;
			unordered_map<int,int> mp;
			int disCount = 0;

			//First window
			for(int i = 0; i < k; i++)
			{
				if(mp[arr[i]] == 0)
				{
					disCount += 1;
				}
				mp[arr[i]] += 1;
			}
			Counts.push_back(disCount);


			//Remaining windows
			for(int i = k; i < n; i++)
			{
				if(mp[arr[i-k]] == 1)
				{
					disCount -= 1;
				}
				mp[arr[i-k]] -= 1;

				if(mp[arr[i]] == 0)
					disCount += 1;
				mp[arr[i]] += 1;

				Counts.push_back(disCount);
			}

			return Counts;
		}
};

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
	#endif

	int n,k;
	cin>>n>>k;
	int arr[n];

	//Take Input 
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	Solution obj;
	vector<int> v = obj.DistinctWindowCount(arr, n, k);

	//Check counts of each window
	for(auto x : v)
	{
		cout << x << ' ';
	}
	return 0;
}

/*

INPUT
7 4
1 2 1 3 4 2 3

OUTPUT
3 4 4 4

*/