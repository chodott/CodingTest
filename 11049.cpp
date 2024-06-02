#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int main()
{
	int n; cin >> n;
	pair<int, int> matrix_dp[501][501];
	int dp[501][501];
	fill(&dp[0][0],  &dp[500][501], 0);
	for (int i = 1; i <= n; ++i)
	{	//초기화
		int r, c;	cin >> r >> c;
		matrix_dp[i][i] = { r,c };
	}

	//범위
	for (int gap = 1; gap < n; ++gap)
	{	//출발지점
		for (int start = 1; start + gap <= n; ++start)
		{	//분기
			int end = start + gap;
			dp[start][end] = INF;
			for (int mid = start; mid < start + gap; ++mid)
			{
				int value = matrix_dp[start][mid].first * matrix_dp[start][mid].second *
					matrix_dp[mid+1][end].second;
				
				dp[start][end] =min(dp[start][end], value + dp[start][mid] + dp[mid+1][end]);
				matrix_dp[start][end] = { matrix_dp[start][mid].first, matrix_dp[mid+1][end].second };

			}
		}
	}
	cout << dp[1][n];
}