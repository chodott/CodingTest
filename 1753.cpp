#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999
int main()
{
	int v, e, root;
	scanf("%d %d", &v, &e);
	scanf("%d", &root);
	root -= 1;
	vector<vector<pair<int, int>>> vec(v, vector<pair<int,int>>());
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> index_q;
	int answer[20000];
	for (int i = 0; i < e; ++i)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		vec[--a].emplace_back(make_pair(w, --b));
	}
	for (int i = 0; i < v; ++i) {answer[i] = INF;}
	answer[root] = 0;
	index_q.push({ 0, root });
	while (!index_q.empty())
	{
		int i = index_q.top().second;
		index_q.pop();
		for (auto& d : vec[i])
		{
			int target = d.second;
			int weight = d.first;
			if (answer[target] <= answer[i] + weight) continue;
			answer[target] = answer[i] + weight;
			index_q.push(d);
		}
	}

	for (int i = 0; i < v; ++i)
	{
		if (answer[i] == INF) printf("INF\n"); 
		else printf("%d\n", answer[i]);
	}
}