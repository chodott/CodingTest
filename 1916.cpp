#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int n, m; cin >> n >> m;
	int dist[1001];
	vector<vector<int>> route_vec(1001,vector<int>(1001, INF));
	fill(&dist[0], &dist[1001], INF);
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> next_pq;
	while (m--)
	{
		int start, end, value;
		cin >> start >> end >> value;
		if (value > route_vec[start][end]) continue;
		route_vec[start][end] = value;
	}

	int start, goal; cin >> start >> goal;
	dist[start] = 0;
	next_pq.push(make_pair(0, start));

	while (!next_pq.empty())
	{
		int value = next_pq.top().first;
		int num = next_pq.top().second;
		next_pq.pop();


		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] <= dist[num] + route_vec[num][i]) continue;
			dist[i] = dist[num] + route_vec[num][i];
			next_pq.push(make_pair(dist[num] + route_vec[num][i], i));
		}
	}

	cout << dist[goal];

}
