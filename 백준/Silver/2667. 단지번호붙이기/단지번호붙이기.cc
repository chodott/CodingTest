#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<vector<char>>& map_vec, vector<int>& answer_vec,  int i, int j)
{
	queue<pair<int, int>> next_q;
	next_q.push(make_pair(i, j));
	int count = 0;
	while (!next_q.empty())
	{
		auto pos = next_q.front();
		next_q.pop();
		int y = pos.first; int x = pos.second;
		if (y < 0 || y >= map_vec.size() || x < 0 || x >= map_vec.size())
		{
			continue;
		}
		if (map_vec[y][x] == '0')
		{
			continue;
		}
		count++;
		next_q.push(make_pair(y + 1, x));
		next_q.push(make_pair(y - 1, x));
		next_q.push(make_pair(y, x-1));
		next_q.push(make_pair(y, x+1));
		map_vec[y][x] = '0';
	}
	answer_vec.push_back(count);
}

int main()
{
	int n; cin >> n;
	vector<vector<char>> map_vec(n,vector<char>(n,false));
	vector<int> answer_vec;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map_vec[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map_vec[i][j] == '1')
			{
				bfs(map_vec, answer_vec, i, j);
			}
		}
	}
	sort(answer_vec.begin(), answer_vec.end(), less<int>());
	cout << answer_vec.size() << "\n";
	for (int count : answer_vec) cout << count << "\n";
}