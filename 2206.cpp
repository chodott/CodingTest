#pragma warning(disable:4996)
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define INF 99999999
int main()
{
	int n, m, answer;
	cin >> n >> m;
	int board[1000][1000][2];
	bool wall[1000][1000];
	queue<tuple<int, int,int, bool>> pos_q;
	fill(&board[0][0][0], &board[999][999][2], INF);
	for (int i = 0; i < n; ++i)
	{
		int b;
		for (int j = 0; j < m; ++j)
		{
			scanf("%1d", &b);
			wall[i][j] = (bool)b;
		}
	}
	pos_q.push(make_tuple(0, 0, 1, 0));
	while (!pos_q.empty())
	{
		int row = get<0>(pos_q.front());
		int column = get<1>(pos_q.front());
		int newCnt = get<2>(pos_q.front());
		bool wallBreak = get<3>(pos_q.front());
		pos_q.pop();

		if (row < 0 || row >= n || column < 0 || column >= m) continue;
		if (wall[row][column])
		{
			if(wallBreak == true) continue;
			wallBreak = true;
		}
		int cnt = board[row][column][wallBreak];
		if (cnt > newCnt)
		{	
			board[row][column][wallBreak] = newCnt;
			pos_q.push(make_tuple(row + 1, column, newCnt + 1, wallBreak));
			pos_q.push(make_tuple(row - 1, column, newCnt + 1, wallBreak));
			pos_q.push(make_tuple(row, column + 1, newCnt + 1, wallBreak));
			pos_q.push(make_tuple(row, column - 1, newCnt + 1, wallBreak));
		}
	}
	
	answer = (board[n - 1][m - 1][0] <= board[n - 1][m - 1][1]) ? board[n - 1][m - 1][0] : board[n - 1][m - 1][1];
	if (answer == INF) cout << -1;
	else cout << answer;
}