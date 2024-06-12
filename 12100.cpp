#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void moveBlock(vector<vector<int>>& board_vec, int dir)
{
	int n = board_vec.size();
	switch (dir)
	{
		int prevIndex;
	case 0:	//위
		for (int i = 0; i < n; ++i)
		{
			prevIndex = 0;
			for (int j = 1; j < n; ++j)
			{
				if (board_vec[j][i] == 0) continue;

				if (board_vec[prevIndex][i] == 0) swap(board_vec[prevIndex][i], board_vec[j][i]);
				else if (board_vec[prevIndex][i] == board_vec[j][i])
				{
					board_vec[prevIndex++][i] = board_vec[j][i] * 2;
					board_vec[j][i] = 0;
				}
				else swap(board_vec[++prevIndex][i], board_vec[j][i]);
			}
		}
		break;
	case 1: //아래
		for (int i = 0; i < n; ++i)
		{
			prevIndex = n-1;
			for (int j = n-2; j >= 0; --j)
			{
				if (board_vec[j][i] == 0) continue;

				if (board_vec[prevIndex][i] == 0) swap(board_vec[prevIndex][i], board_vec[j][i]);
				else if (board_vec[prevIndex][i] == board_vec[j][i])
				{
					board_vec[prevIndex--][i] = board_vec[j][i] * 2;
					board_vec[j][i] = 0;
				}
				else swap(board_vec[--prevIndex][i], board_vec[j][i]);
			}
		}
		break;

	case 2:	//좌
		for (int i = 0; i < n; ++i)
		{
			prevIndex = 0;
			for (int j = 1; j < n; ++j)
			{
				if (board_vec[i][j] == 0) continue;

				if (board_vec[i][prevIndex] == 0) swap(board_vec[i][prevIndex], board_vec[i][j]);
				else if (board_vec[i][prevIndex] == board_vec[i][j])
				{
					board_vec[i][prevIndex++] = board_vec[i][j] * 2;
					board_vec[i][j] = 0;
				}
				else swap(board_vec[i][++prevIndex], board_vec[i][j]);
			}
		}
		break;

	case 3:	//우
		for (int i = 0; i < n; ++i)
		{
			prevIndex = n-1;
			for (int j = n-2; j >= 0; --j)
			{
				if (board_vec[i][j] == 0) continue;

				if (board_vec[i][prevIndex] == 0) swap(board_vec[i][prevIndex], board_vec[i][j]);
				else if (board_vec[i][prevIndex] == board_vec[i][j])
				{
					board_vec[i][prevIndex--] = board_vec[i][j] * 2;
					board_vec[i][j] = 0;
				}
				else swap(board_vec[i][--prevIndex], board_vec[i][j]);
			}
		}
		break;
	}
}
void dfs(vector<vector<int>>& board_vec, int count)
{
	if (count == 5)
	{	//종료 조건 시 최대값 도출
		int n = board_vec.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				answer = max(answer, board_vec[i][j]);
			}
		}
		return;
	}

	for (int dir = 0; dir < 4; ++dir)
	{
		vector<vector<int>> temp = board_vec;
		moveBlock(temp, dir);
		dfs(temp, count + 1);
	}
}
int main()
{
	int n; cin >> n;
	vector<vector<int>> board_vec(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> board_vec[i][j];
	}
	dfs(board_vec, 0);
	cout << answer;
}