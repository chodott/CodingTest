#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int BFS(char map[][25], int i, int j, int max)
{
	queue<pair<int, int>> q;
	int count = 0;
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		auto pos = q.front();
		int y = pos.first;
		int x = pos.second;
		q.pop();


		if (x < 0 || x >= max || y < 0 || y >= max)
		{
			continue;
		}

		if (map[y][x] != '1')
		{
			continue;
		}

		q.push(make_pair(y + 1, x));
		q.push(make_pair(y - 1, x));
		q.push(make_pair(y, x + 1));
		q.push(make_pair(y, x - 1));
		count++;
		map[y][x] = '0';
	}

	return count;
}

int main()
{
	//Init
	int n; cin >> n;
	char map[25][25];
	vector<int> answers;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	//Search
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == '1')
			{
				answers.emplace_back(BFS(map, i, j, n));
			}
		}
	}

	sort(answers.begin(), answers.end(), less<int>());

	cout << answers.size() << "\n";
	for (int answer : answers)
	{
		cout << answer << "\n";
	}

}