#include <iostream>
#include <queue>
#include <tuple>
#include <deque>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>> next_pq;
	deque<int> root[1001];
	int data[1001][1001];
	int distance[1001];
	int n, m; cin >> n >> m;
	fill(&data[0][0], &data[1000][1001], INF);
	fill(&distance[0], &distance[1001], INF);
	for (int i = 0; i < m; ++i)
	{
		int s, e, v;
		cin >> s >> e >> v;
		if (v > data[s][e]) continue;
		data[s][e] = v;
	}
	int start, end;
	cin >> start >> end;
	for (int i = 1; i <= n; ++i)
	{
		int value = data[start][i];
		if (value == INF) continue;
		next_pq.push(make_tuple(value, start, i));
	}
	distance[start] = 0;
	while (!next_pq.empty())
	{
		int destination = get<2>(next_pq.top());
		int startPos = get<1>(next_pq.top());
		int value = get<0>(next_pq.top());
		next_pq.pop();
		if (distance[destination] <= value + distance[startPos]) continue;

		distance[destination] = value + distance[startPos];
		root[destination] = root[startPos];
		root[destination].emplace_back(destination);

		for (int i = 1; i <= n; ++i)
		{
			if (data[destination][i] == INF) continue;
			next_pq.push(make_tuple(data[destination][i], destination, i));
		}
	}
	cout << distance[end] << "\n";
	cout << root[end].size() + 1 << "\n";
	cout << start << " ";
	for (int num : root[end]) cout << num << " ";
}