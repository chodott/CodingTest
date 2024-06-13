#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
풀이
map<int, vector<pair<int,int>>> 물고기의 크기를 key값으로 물고기의 위치를 저장한 벡터를 통해
상어의 크기에 따라 value 값에 접근하고 물고기 위치 벡터를 현재 상어의 위치와 가까운 순으로 정렬하는 방식을 떠올렸으나,
가장 가깝더라도 크기가 큰 물고기가 가로막고 있지 않을 것이란 보장이 없기에 매번 bfs로 이동 위치를 탐색하기로 결정.


왜 예제 3번 답이 안나오나 했더니 - 같은 물고기 크기도 지나가지 않고 있었다.!

*/

int main()
{
	int n; cin >> n;
	int size = 2; int count = 0; int answer = 0;
	vector<vector<int>> map_vec(n, vector<int>(n, 0));
	vector<vector<bool>> visited_vec(n, vector<bool>(n, false));
	priority_queue<tuple<int ,int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> nextPos_q; //이동횟수, y, x
	tuple<int, int, int> pos;

	//맵 초기화
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map_vec[i][j];
			if (map_vec[i][j] == 9)
			{
				map_vec[i][j] = 0;
				pos = { 0,i,j };
			}
		}
	}

	nextPos_q.push(pos);
	while (!nextPos_q.empty())
	{
		int length = get<0>(nextPos_q.top());
		int y = get<1>(nextPos_q.top());
		int x = get<2>(nextPos_q.top());
		nextPos_q.pop();

		//중복을 방지하기 위해 방문 맵을 관리
		if (y < 0 || x < 0 || y >= n || x >= n) continue;
		if (visited_vec[y][x] == true) continue;
		if (map_vec[y][x] > size)continue;
		else if (map_vec[y][x] == size) {}
		else if (map_vec[y][x] > 0)
		{
			++count;
			if (count == size)
			{
				size += 1;
				count = 0;
			}
			answer += length;
			length = 0;
			nextPos_q = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>();
			map_vec[y][x] = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					visited_vec[i][j] = false;
				}
			}
		}
		
		visited_vec[y][x] = true;

		nextPos_q.push(make_tuple(length+1, y + 1, x));
		nextPos_q.push(make_tuple(length + 1,y, x-1));
		nextPos_q.push(make_tuple(length + 1,y, x+1));
		nextPos_q.push(make_tuple(length + 1, y-1, x));
	}
	cout << answer;
}