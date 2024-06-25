#include <iostream>
#include <vector>
using namespace std;
#define SIZE 10

bool board[SIZE][SIZE];
bool returnAble(int length, int row, int column)
{
	if (row + length >= SIZE || column + length >= SIZE) return false;
	for (int i = row; i <= row+length; ++i)
	{
		for (int j = column; j <= column + length; ++j)
		{
			if (board[i][j] == false) 
				return false;
		}
	}
	return true;
}

bool returnSuccess()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (board[i][j] == 1) return false;
		}
	}
	return true;
}

void fillBoard(int row, int column, int len, bool value)
{
	for (int i = row; i <= row + len; ++i)
	{
		for (int j = column; j <= column + len; ++j)
		{
			board[i][j] = value;
		}
	}
}

void dfs(vector<int>& paperCnt_vec, int& answer, int cnt)
{
	if (returnSuccess() == true)
	{	//조건 달성
		answer = min(answer, cnt);
		return;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{	//1 찾기
			if (board[i][j] == true)
			{
				for (int len = 4; len >= 0; --len)
				{
					if (paperCnt_vec[len] == 0) continue;
		
					if (returnAble(len, i, j) == true)
					{
						fillBoard(i, j, len, false);
						paperCnt_vec[len] -= 1;
						dfs(paperCnt_vec, answer, cnt+1);
						fillBoard(i, j, len, true);
						paperCnt_vec[len] += 1;
					}
				}
				return;
			}
		}
	}

}

int main()
{
	vector<int> paperCnt_vec(5, 5);
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			bool value; cin >> value;
			board[i][j] = value;
		}
	}
	int answer = 100;
	dfs(paperCnt_vec, answer, 0);
	answer = answer == 100 ? -1 : answer;
	cout << answer;
}