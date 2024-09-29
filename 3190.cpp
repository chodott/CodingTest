#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool move(vector<pair<int, int>>& snake_vec, vector<vector<bool>>& board_vec, int direction)
{
	int n = board_vec.size();
	int y = snake_vec[0].first; int x = snake_vec[0].second;
	pair<int, int> nextPos = {y, x};
	switch (direction)
	{
	case 0:
		nextPos = { y, x + 1 };
		break;
	case 1:
		nextPos = { y + 1,x };
		break;
	case 2:
		nextPos = { y,x-1};
		break;
	case 3:
		nextPos = { y-1,x };
		break;
	}
	if (nextPos.first < 0 || nextPos.first >= n || nextPos.second < 0 || nextPos.second >= n)
		return false;

	if (board_vec[nextPos.first][nextPos.second] == true)
	{
		snake_vec.emplace_back(snake_vec.back());
		board_vec[nextPos.first][nextPos.second]= false;
	}
	for (int i = snake_vec.size()-1; i >=1; --i)
	{
		if (snake_vec[i] == nextPos) return false;
		snake_vec[i] = snake_vec[i - 1];
	}
	snake_vec[0] = nextPos;
	return true;
}

int main()
{
	int n; cin >> n;
	int k; cin >> k;
	queue<pair<int, char>> rotate_queue;
	vector<vector<bool>> board_vec(n, vector<bool>(n, false));
	vector<pair<int, int>> snake_vec(1, { 0,0 });
	int direction = 0;	// 0 : right		1: down	2: left	3: up
	while (k--)
	{	//apple pos
		int y, x; cin >> y >> x;
		board_vec[y-1][x-1] = true;
	}
	int l; cin >> l;
	while (l--)
	{	//rotate timing
		int s; char c; cin >> s >> c;
		rotate_queue.push(make_pair(s, c));
	}
	int second = 0;
	while (1)
	{
		++second;
		if (move(snake_vec, board_vec, direction) == false)
		{
			cout << second;
			return 0;
		}
		if (rotate_queue.empty()) continue;
		if (second == rotate_queue.front().first)
		{
			if (rotate_queue.front().second == 'D') ++direction %= 4;
			else
			{
				direction--;
				direction = direction < 0 ? 3 : direction;
			}
			rotate_queue.pop();
 		}
	}
}