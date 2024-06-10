#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int returnVirusCnt(vector<vector<int>> map, vector<int>& wallPos_vec, vector<pair<int,int>>& virus_vec, int& m)
{
	int count = 0;
	for (int i = 0; i < 3; ++i) 
	{	//조합에 따라 3개의 벽 배치
		int id = wallPos_vec[i];
		map[id / m][id % m] = 1;
	}

	//bfs 바이러스 개수 탐색
	queue<pair<int,int>> virus_q;
	for (auto& pos : virus_vec) virus_q.push(pos);
	while (!virus_q.empty())
	{
		int y = virus_q.front().first; int x = virus_q.front().second;
		virus_q.pop();
		if (y >= map.size() || y < 0 || x < 0 || x >= m) continue;
		if (map[y][x] != 0) continue;

		map[y][x] = 2;
		++count;
		virus_q.push(make_pair(y - 1, x));
		virus_q.push(make_pair(y + 1, x));
		virus_q.push(make_pair(y , x+1));
		virus_q.push(make_pair(y , x-1));
	}
	return count;
}

int main()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<int> id_vec; vector<pair<int,int>> virus_vec;
	int wallCnt = 0; int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			int id = i * m + j;
			if (map[i][j] == 1) wallCnt++;
			else if (map[i][j] == 0) id_vec.emplace_back(id);
			else
			{
				virus_vec.emplace_back(make_pair(i, j));
				map[i][j] = 0;
			}
		}
	}
	wallCnt += 3;

	//벽 세개 위치
	vector<bool> temp(id_vec.size(), true);
	for (int i = 0; i < 3; ++i) temp[i] = false;
	do
	{
		vector<int> wall_vec;
		for (int i=0;i<temp.size(); ++i)
		{
			if (temp[i] == false) wall_vec.emplace_back(id_vec[i]);
		}
		int safeCnt = n * m - wallCnt - returnVirusCnt(map, wall_vec, virus_vec, m);
		answer = max(answer, safeCnt);
	} while (next_permutation(temp.begin(), temp.end()));
	
	cout << answer;
}