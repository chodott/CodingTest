#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define INF 99999987654321
int main()
{
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	long long dist[500];
	bool bCycle = false;
	fill(&dist[0], &dist[500], INF);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace_back(make_tuple(--a, --b, c));
	}

	dist[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (auto& edge: edges)
		{
			int start = get<0>(edge);
			int end = get<1>(edge);
			int weight = get<2>(edge);

			if (dist[start] == INF) continue;
			if (dist[end] <= weight + dist[start]) continue;
			dist[end] = weight + dist[start];

			if (i == n - 1) bCycle = true;
		}
	}

	if (bCycle == true)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i < n; ++i)
	{
		if (dist[i] == INF) cout << -1<<endl;
		else cout << dist[i]<<endl;
	}
}