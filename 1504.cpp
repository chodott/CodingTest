#include <iostream>

#define INF 987654321
using namespace std;
//플로이드 와샬
int main()
{
	int n, m;
	cin >> n >> m;

	int data[100][100];
	fill(&data[0][0], &data[99][100], INF);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (data[--a][--b] <= c) continue;
		data[a][b] = c;
	}
	for (int i = 0; i < n; ++i) data[i][i] = 0;

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				data[i][j] = min(data[i][j], data[i][k] + data[k][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (data[i][j] == INF) cout << "0";
			else cout << data[i][j];
			cout<< " ";
		}
		cout << endl;
	}
}