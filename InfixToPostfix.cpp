#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch)
{
	if (ch == '^')
		return 3;
	else if (ch == '/' or ch == '*')
		return 2;
	else if (ch == '+' or ch == '-')
		return 1;
	else
		return -1;
}

string InfixToPostfix(string str)
{
	stack<char> st;
	string ans;

	for (char ch : str)
	{
		if (isalnum(ch))
			ans.push_back(ch);
		else if (ch == '(')
			st.push(ch);
		else if (ch == ')')
		{
			while (st.top() != '(')
			{
				ans.push_back(st.top());
				st.pop();
			}
			// Also pop the '('
			st.pop();
		}
		else {
			while (!st.empty() and precedence(ch) <= precedence(st.top()))
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
#endif

	string str;
	cin >> str;
	cout << InfixToPostfix(str) << endl;



	return 0;
}