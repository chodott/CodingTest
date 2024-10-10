#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n; cin >> m >> n;
	vector<vector<bool>> map_vec(n, vector<bool>(m, false));
	vector<vector<int>> break_cnt(n,vector<int>(m,INF));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> next_pq;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		for (int j = 1; j <= m; ++j)
		{
			map_vec[i][m-j] = atoi(&s.back());
			s.pop_back();
		}
	}
	next_pq.push(make_tuple(0, 0, 0));
	while (!next_pq.empty())
	{
		int y = get<0>(next_pq.top());
		int x = get<1>(next_pq.top());
		int cnt = get<2>(next_pq.top());
		next_pq.pop();
		if (y < 0 || x < 0 || y >= n || x >= m) continue;
		if (map_vec[y][x]) cnt++;
		if (break_cnt[y][x] <= cnt) continue;
		break_cnt[y][x] = cnt;
		next_pq.push(make_tuple(y - 1, x, cnt));
		next_pq.push(make_tuple(y + 1, x, cnt));
		next_pq.push(make_tuple(y , x +1, cnt));
		next_pq.push(make_tuple(y , x-1, cnt));
	}

	cout << break_cnt[n - 1][m - 1];

}