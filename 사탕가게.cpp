#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& c1, pair<int, int>& c2)
{
	return c1.second < c2.second;
}

int main()
{
	int n; float m;
	vector<int> sum_vec;
	vector<int> answer_vec;
	int dp[10001];

	while (-1)
	{
		fill(&dp[0], &dp[10001], 0);
		cin >> n; cin >> m;
		m *= 100;
		if (n == 0) break;
		vector<pair<int, int>> candy_vec = {};
		for (int i = 0; i < n; ++i)
		{
			int cal; float price;
			cin >> cal >> price;
			candy_vec.emplace_back(make_pair(cal, price* 100));
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = candy_vec[i].second; j <= m; ++j)
			{
				dp[j] = max(dp[j], dp[j-candy_vec[i].second] + candy_vec[i].first);
			}
		}

		answer_vec.emplace_back(dp[(int)(m)]);
	}
	for (int answer : answer_vec) cout << answer << endl;
}