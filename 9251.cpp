#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string s1, s2;

	int dp[1001][1001];
	int answer = 0;
	cin >> s1 >> s2;
	for (int i = 0; i <= s1.length(); ++i) dp[i][0] = 0;
	for (int i = 0; i <= s2.length(); ++i) dp[0][i] = 0;

	for (int i = 1; i <= s1.length(); ++i)
	{
		for (int j = 1; j <= s2.length(); ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(dp[i][j], answer);
			}
			else
			{
				int value = max(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = value;
			}
		}
	}
	cout << answer;
}