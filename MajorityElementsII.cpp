#include <iostream>
#include <vector>
using namespace std;

vector<int> MajorityElementsII(vector<int> nums) {
	int len = nums.size();

	int el1 = -1, ct1 = 0;
	int el2 = -1, ct2 = 0;

	for(int num: nums) {
		if(el1 == num)
			ct1++;
		else if(el2 == num)
			ct2++;
		else if(ct1 == 0)
		{
			el1 = num;
			ct1 = 1;
		}
		else if(ct2 == 0)
		{
			el2 = num;
			ct2 = 1;
		}
		else
		{
			--ct1, --ct2;
		}
	}

	ct1 = 0, ct2 = 0;
	for(int num: nums) {
		if(num == el1)ct1++;
		else if(num == el2)ct2++;
	}

	vector<int> ans;
	if(ct1 > len/3)
		ans.push_back(el1);
	if(ct2 > len/3)
		ans.push_back(el2);
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	}

	// for(auto it: vec) {
	// 	cout << it << ' ';
	// }

	vector<int> ans = MajorityElementsII(vec);
	for(auto it: ans) {
		cout << it << ' ';
	}
	
	return 0;
}