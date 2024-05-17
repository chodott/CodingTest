//백준 골드5 동전1 문제

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> value_vec;
	vector<int> dp(k+1, 0);
	dp[0] = 1;
	for(int i = 0; i < n;++i)
	{
		int value;
		cin >> value;
		value_vec.emplace_back(value);
	}

	for (int i = 0; i <n; ++i)
	{
		for (int j = value_vec[i]; j <= k; ++j)
		{
			dp[j] += dp[j - value_vec[i]];
		}
	}
	cout << dp[k];
}