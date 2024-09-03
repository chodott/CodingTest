#include <iostream>
#include <vector>

using namespace std;

void findMax(vector<vector<int>>& board_vec, int i, int j, int cnt, int& answer, int sum, int dir)
{
	if (i < 0 || j < 0 || i >= board_vec.size() || j >= board_vec[0].size()) return;
	sum += board_vec[i][j];
	if (cnt == 1)
	{
		answer = sum < answer ? answer : sum;
		return;
	}
	if(dir != 1) findMax(board_vec,i + 1, j, cnt - 1, answer, sum,3);
	if(dir != 4) findMax(board_vec, i, j+1, cnt - 1, answer, sum,2);
	if(dir != 3) findMax(board_vec, i-1,j, cnt - 1, answer, sum,1);
	if(dir != 2) findMax(board_vec, i, j - 1, cnt - 1, answer,sum,4);
}

void findMax(vector<vector<int>>& board_vec, int i, int j, int& answer)
{
	int max = 0;
	int sum;
	if (i > 0 && j > 0 && j < board_vec[0].size() - 1)
	{	//で
		sum = board_vec[i][j] + board_vec[i - 1][j] + board_vec[i][j - 1] + board_vec[i][j + 1];
		max = max > sum ? max : sum;
	}
	if (i > 0 && j > 0 && i < board_vec.size() - 1)
	{	//っ
		sum = board_vec[i][j] + board_vec[i - 1][j] + board_vec[i][j - 1] + board_vec[i + 1][j];
		max = max > sum ? max : sum;
	}
	if (i > 0 && j < board_vec[0].size() - 1 && i < board_vec.size() - 1)
	{	// た
		sum = board_vec[i][j] + board_vec[i - 1][j] + board_vec[i][j + 1] + board_vec[i + 1][j];
		max = max > sum ? max : sum;
	}
	if (i < board_vec.size()-1 && j> 0 && j < board_vec[0].size()-1)
	{	//ぬ
		sum = board_vec[i][j] + board_vec[i + 1][j] + board_vec[i][j - 1] + board_vec[i][j + 1];
		max = max > sum ? max : sum;
	}
	answer = answer > max ? answer : max;
}

int main()
{
	int n, m;
	int answer = 0;
	cin >> n >> m;
	vector<vector<int>> board_vec(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board_vec[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			findMax(board_vec, i, j, 4, answer, 0, 0);
			findMax(board_vec, i, j, answer);
		}
	}

	cout << answer;
}