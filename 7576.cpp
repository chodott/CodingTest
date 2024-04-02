#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> tomato_vec(m, vector<int>(n, 0));
	queue<pair<int, int>> tomato_q;
	int state;
	int answer = -1;
	int cnt = 0; int maxCnt = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> state;
			tomato_vec[i][j] = state;
			if (state != 1) continue;
			tomato_q.push(make_pair(i, j));
		}
	}
	cnt = 0;
	maxCnt = tomato_q.size();
	while (!tomato_q.empty())
	{
		int row = tomato_q.front().first;;
		int column = tomato_q.front().second;
		tomato_q.pop();
		
		if (row < 0 || row >= m || column < 0 || column >= n) {}
		else if(tomato_vec[row][column] == 0 || answer == -1)
		{
			tomato_vec[row][column] = 1;
			tomato_q.push(make_pair(row - 1, column));
			tomato_q.push(make_pair(row + 1, column));
			tomato_q.push(make_pair(row, column - 1));
			tomato_q.push(make_pair(row, column + 1));
		}
		cnt++;
		if (cnt == maxCnt)
		{
			answer++;
			cnt = 0;
			maxCnt = tomato_q.size();
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (tomato_vec[i][j] != 0) continue;

			answer = -1;
			break;
		}
	}
	cout << answer-1;
}