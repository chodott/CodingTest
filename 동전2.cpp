#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 10001

int main()
{
	int n, k;
	cin >> n >> k;
	int coin[101];
	int answer[10001];
	fill(&answer[0], &answer[10000], INF);
	answer[0] = 0;
	for (int i = 1; i <=n; ++i)
	{
		cin >> coin[i];
		for (int j = coin[i]; j <= k; ++j)
		{
			int newValue = answer[j - coin[i]] + 1;
			answer[j] = answer[j] < newValue ? answer[j] : newValue;
		}
	}

	if (answer[k] == INF) cout << -1;
	else cout << answer[k];
}