#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> dest_vec[50000];
	vector<int> dist_vec;
	priority_queue<int> pq;
	for (int i = 0; i < m; ++i)
	{
		int start, end, value;
		cin >> start >> end >> value;
		start -= 1; end -= 1;
		dest_vec[start].emplace_back(make_pair(end, value));
		dest_vec[end].emplace_back(make_pair(start, value));
	}
	for (int i = 0; i < n; ++i) dist_vec.emplace_back(INF);
	dist_vec[0] = 0;
	pq.push(0);
	while (!pq.empty())
	{
		int index = pq.top();
		pq.pop();

		for (int i=0; i<dest_vec[index].size(); ++i)
		{
			int next = dest_vec[index][i].first;
			int value = dest_vec[index][i].second;
			if(dist_vec[next] > value + dist_vec[index])
			{
				dist_vec[next] = value + dist_vec[index];
				pq.push(next);
			}
		}
	}

	cout << dist_vec[n-1];
}