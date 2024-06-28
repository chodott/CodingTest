#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//bfs를 통한 완전탐색.
//상하좌우 기울이기, 카운트 > 10 = -1리턴

struct info
{
	int rx, ry, bx, by;
	int cnt = 0; int dir = -1;
	void setPos(int y, int x, bool type)
	{
		if (type) {rx = x; ry = y;}
		else { bx = x; by = y; }
	}
};

bool moveMarble(vector<vector<char>>& board, int& y, int& x, int& dy, int& dx, int dir)
{
	int len = board[0].size();
	while (-1)
	{
		int newY = y; int newX = x;
		switch (dir)
		{
		case 0: newY--; break;
		case 1 :newY++; break;
		case 2: newX--; break;
		case 3: newX++; break;
		}

		if (newX == dx && newY == dy) return false;
		else if (board[newY][newX] == '.') { y = newY; x = newX; }
		else if (board[newY][newX] == 'O')
		{
			x = -1; y = -1;	//충돌을 막기 위해 위치 초기화
			return true;
		}
		else return false;
	}
}

int returnMoveResult(vector<vector<char>>& board, info& data, int dir)
{
	bool blueGoal = false; bool redGoal = false;
	switch (dir)
	{
	case 0:
		if (data.dir == 1) return -1;
		if (data.by < data.ry) { blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir);}
		else { redGoal = moveMarble(board,data.ry, data.rx, data.by, data.bx, dir); blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); }
		break;
	case 1:
		if (data.dir == 0) return -1;
		if (data.by > data.ry) { blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); }
		else { redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); }
		break;
	case 2:
		if (data.dir == 3) return -1;
		if (data.bx < data.rx) { blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); }
		else { redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); }
		break;
	case 3:
		if (data.dir == 2) return -1;
		if (data.bx > data.rx) { blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); }
		else { redGoal = moveMarble(board, data.ry, data.rx, data.by, data.bx, dir); blueGoal = moveMarble(board, data.by, data.bx, data.ry, data.rx, dir); }
		break;
	}
	data.cnt += 1; data.dir = dir;
	if (blueGoal) return -1;
	else if (redGoal) return 1;
	else return 0;
}

int main()
{
	int n, m; cin >> n >> m;
	int answer = -1;
	vector<vector<char>> board_vec(n,vector<char>(m, '#'));
	queue<info> info_q;
	info firstInfo;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board_vec[i][j];
			if (board_vec[i][j] == 'R') { firstInfo.setPos(i, j, true); board_vec[i][j] = '.'; }
			else if (board_vec[i][j] == 'B') { firstInfo.setPos(i, j, false), board_vec[i][j] = '.'; };
		}
	}
	info_q.push(firstInfo);

	while (!info_q.empty())
	{
		for (int i = 0; i < 4; ++i)
		{
			info newInfo = info_q.front();
			int result = returnMoveResult(board_vec, newInfo, i);
			//cout << newInfo.cnt << " " << i << ":" << result<<endl;
			if(result == 0 && newInfo.cnt < 10) info_q.push(newInfo);
			else if (result == -1) continue;
			else if (result == 1)
			{
				answer = newInfo.cnt;
				cout << answer;
				return 0;
			}
		}
		info_q.pop();
	}
	cout << answer;
}