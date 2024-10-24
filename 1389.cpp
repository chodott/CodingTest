#include <iostream>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int arr[101][101];
	int n, m; cin >> n >> m;
	fill(&arr[0][0], &arr[100][101], INF);
	while (m--)
	{
		int a, b; cin >> a >> b;
		arr[a][b] = 1; arr[b][a] = 1;
	}
	for (int i = 1; i <= n; ++i) arr[i][i] = 0;
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}

	pair<int, int> minNum = { INF,0 };
	for (int i = 1; i <= n; ++i)
	{	
		int sum = 0;
		for (int j = 1; j <= n; ++j)
		{
			sum += arr[i][j];
		}
		minNum = minNum.first <= sum ? minNum : make_pair(sum, i);
	}
	cout << minNum.second;
}