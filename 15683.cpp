#include <iostream>
#include <vector>
#include <tuple>
#define SEE 9

/*
풀이
1. 회전 의미가 없는 5번 카메라는 입력 받으면서 적용
2. 나머지 카메라를 90도씩 돌리면서 최소 사각지대 도출
*/
using namespace std;

int answer = 987654321;

void applyCctv(vector<vector<int>>& map, pair<int,int> pos,  int direction)
{
	while (1)
	{
		switch (direction)
		{
		case 0:	 ++pos.first; break;
		case 1: ++pos.second; break;
		case 2: --pos.first; break;
		case 3: --pos.second; break;
		}
		if (pos.first < 0 || pos.first >= map.size() || pos.second < 0 || pos.second >= map[0].size()) return;
		if (map[pos.first][pos.second] == 6) break;
		else if (map[pos.first][pos.second] != 0) continue;
		map[pos.first][pos.second] = SEE;
	}
}

void dfs(vector<vector<int>>& map, vector<tuple<int, int, int>>& cctvData_vec, int index)
{
	if (index == cctvData_vec.size())
	{
		int count = 0;
		for (int i = 0; i < map.size(); ++i)
		{
			for (int j = 0; j < map[i].size(); ++j)
			{
				if (map[i][j] == 0) 
					count++;
			}
		}
		answer = min(answer, count);
		return;
	}

	int type = get<2>(cctvData_vec[index]);
	int y = get<0>(cctvData_vec[index]); int x = get<1>(cctvData_vec[index]);
	for (int dir = 0; dir < 4; ++dir)
	{
		vector<vector<int>> newMap = map;
		switch (type)
		{
		case 1: 
			applyCctv(newMap, {y,x}, dir); 
			break;
		case 2: 
			applyCctv(newMap, { y,x }, dir);
			applyCctv(newMap, { y,x }, (dir + 2)%4);
			break;
		case 3:
			applyCctv(newMap, { y,x }, dir);
			applyCctv(newMap, { y,x }, (dir + 1)%4);
			break;
		case 4:
			applyCctv(newMap, { y,x }, dir);
			applyCctv(newMap, { y,x }, (dir + 1)%4);
			applyCctv(newMap, { y,x }, (dir + 2)%4);
			break;
		}
		dfs(newMap, cctvData_vec, index + 1);
	}
}


int main()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> map_vec(n, vector<int>(m, 0));
	vector<tuple<int, int, int>> cctvData_vec;
	vector<pair<int, int>> cctv5_vec;
	//맵 초기화, 5번 CCTV 반영
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map_vec[i][j];
			if (map_vec[i][j] == 6 || map_vec[i][j] == 0) continue;
			else if (map_vec[i][j] == 5) cctv5_vec.emplace_back(make_pair(i, j));
			else cctvData_vec.emplace_back(make_tuple(i, j, map_vec[i][j]));
		}
	}

	for (int i = 0; i < cctv5_vec.size(); ++i)
	{
		for (int dir = 0; dir < 4; ++dir) applyCctv(map_vec, cctv5_vec[i], dir);
	}

	dfs(map_vec, cctvData_vec, 0);

	cout << answer;
}