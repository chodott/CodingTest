#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int n, m;
	int board[101];
	map<int, int> ladder_map;
	map<int, int> snake_map;
	queue<pair<int,int>> count_q;
	cin >> n >> m;
	int start, end;

	fill(&board[0], &board[101], 99999);
	for (int i = 0; i < n + m; ++i)
	{
		cin >> start >> end;
		if (i < n) ladder_map[start] = end;
		else snake_map[start] = end;
	}
	count_q.push(make_pair(1, 0));
	while (!count_q.empty())
	{
		int index = count_q.front().first;
		int cnt = count_q.front().second;
		count_q.pop();
		if (board[index] <= cnt || index > 100) continue;

		board[index] = cnt;
		if (index == 100) 
			break;

		for (int i = 1; i <= 6; ++i)
		{
			int next = index + i;
			if (ladder_map.find(next) != ladder_map.end()) next = ladder_map[next];
			if (snake_map.find(next) != snake_map.end()) next = snake_map[next];
			count_q.push(make_pair(next, cnt + 1));
		}
	}

	cout << board[100];
}