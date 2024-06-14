#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

void djikstra(vector<int>& time_vec, vector<vector<pair<int, int>>>& data_vec, int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next_pq;
	next_pq.push({ 0,x });
	time_vec[x] = 0;
	while (!next_pq.empty())
	{
		int time = next_pq.top().first;
		int pos = next_pq.top().second;
		next_pq.pop();
		for (auto& next : data_vec[pos])
		{
			if (time_vec[next.second] <= next.first + time) continue;
			time_vec[next.second] = next.first + time;
			next_pq.push({next.first + time, next.second});
		}
	}
}

int main()
{
	int n, m, x; cin >> n >> m >> x;
	int answer = 0;
	vector<vector<int>> time_vec(2, vector<int>(n+1, INF));
	vector<vector<pair<int, int>>> data_vec[2];
	
	for (int i = 0; i <= n; ++i)
	{
		data_vec[0].emplace_back(vector<pair<int, int>>());
		data_vec[1].emplace_back(vector<pair<int, int>>());
	}
	while (m--)
	{
		int start, end, time;
		cin >> start >> end >> time;
		data_vec[0][start].emplace_back(make_pair(time, end));
		data_vec[1][end].emplace_back(make_pair(time, start));
	}

	djikstra(time_vec[0], data_vec[0], x);
	djikstra(time_vec[1], data_vec[1], x);

	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, time_vec[0][i] + time_vec[1][i]);
	}
	cout << answer;
}






















//플로이드 와샬 풀이
//int main()
//{
//	int n, m, x; cin >> n >> m >> x;
//	int data[1001][1001];
//	fill(&data[0][0],  & data[1000][1001], INF);
//	while (m--)
//	{
//		int start, end, time;
//		cin >> start >> end >> time;
//		data[start][end] = time;
//	}
//
//	for (int i = 1;  i <= n; ++i) data[i][i] = 0;
//
//	for (int mid = 1; mid <= n; ++mid)
//	{
//		for (int i = 1; i <= n; ++i)
//		{
//			for (int j = 1; j <= n; ++j)
//			{
//				if (data[i][mid] == INF || data[mid][j] == INF) continue;
//				data[i][j] = min(data[i][j], data[i][mid] + data[mid][j]);
//			}
//		}
//	}
//
//	int answer = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		answer = max(answer, data[i][x] + data[x][i]);
//	}
//	cout << answer;
//}