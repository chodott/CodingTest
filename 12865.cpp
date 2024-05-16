#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int dp[101][100001];
	int w, v;
	pair<int, int> data[101];
	fill(&dp[0][0], &dp[100][100001], 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> w >> v;
		data[i] = { w,v };
	}

	for (int i = 0; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (data[j].first <= i)
			{	//j번째 물건이 들어갈 수 있는 경우

				dp[j][i] = max(dp[j - 1][i], data[j].second + dp[j - 1][i - data[j].first]);
			}
			else dp[j][i] = dp[j - 1][i];
		}
	}

	cout << dp[n][k];
}