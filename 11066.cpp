#include <iostream>
using namespace std;

#define INF 987654321

//비용 - 파일의 합
int main()
{
	int t;
	cin >> t;
	int dp[501][501];
	int sum[501];
	while (t--)
	{
		int k;
		cin >> k;
		fill(&dp[0][0], &dp[500][501], 0);
		fill(&sum[0], &sum[501], 0);

		for (int i = 1; i <= k; ++i)
		{
			int a; cin >> a;
			sum[i] = sum[i - 1] + a;
		}

		//연산 범위 num ~ num+i
		for (int i = 1; i < k; ++i)
		{	//시작 위치
			for (int j = 1; j +i  <= k; ++j)
			{	//분할 위치
				dp[j][j + i] = INF;
				for (int l = j; l< j +i; ++l)
				{
					dp[j][j + i] = min(dp[j][j + i], 
												dp[j][l] + dp[l + 1][j + i]+ sum[j+i] - sum[j-1]);
					
				}
			}
		}
		cout << dp[1][k ] << "\n";
	}
}