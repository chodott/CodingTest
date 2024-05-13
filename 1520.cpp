#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

//작은 수로만 이동하기 때문에 방향을 신경쓸 필요는 없당

struct compare
{
	bool operator() (tuple<int, int, int,int>& t1, tuple<int, int, int,int>& t2)
	{
		return get<0>(t1) < get<0>(t2);
	}
};

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> map(m, vector<int>(n, 0));
	vector < vector<bool>> visited(m, vector<bool>(n, false));
	vector<vector<int>> dp(m, vector<int>(n, 0));
	priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, compare> heightPos_q;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}
	heightPos_q.push(make_tuple(10000, 0, 0, -1));
	dp[0][0] = 1;

	while (!heightPos_q.empty())
	{
		tuple<int, int, int, int> temp = heightPos_q.top();
		int prevHeight = get<0>(temp);
		int prevRow = get<1>(temp);
		int prevColumn = get<2>(temp);
		int type = get<3>(temp);
		heightPos_q.pop();

		int row = prevRow;
		int column = prevColumn;

		switch (type)
		{
		case 0: row--; break;
		case 1: row++; break;
		case 2: column--; break;
		case 3: column++; break;
		}

		if (row < 0 || column < 0 || row >= m || column >= n) continue;
		int curHeight = map[row][column];
		if (curHeight >= prevHeight) continue;

		dp[row][column] += dp[prevRow][prevColumn];
		if (type == -1) dp[row][column] = 1;
		
		if (visited[row][column] == true) continue;
		for (int t = 0; t < 4; ++t) heightPos_q.push(make_tuple(curHeight, row, column, t));
		visited[row][column] =true;

	}
	cout << dp[m - 1][n - 1];
}