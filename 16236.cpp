#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
Ǯ��
map<int, vector<pair<int,int>>> ������� ũ�⸦ key������ ������� ��ġ�� ������ ���͸� ����
����� ũ�⿡ ���� value ���� �����ϰ� ����� ��ġ ���͸� ���� ����� ��ġ�� ����� ������ �����ϴ� ����� ���÷�����,
���� �������� ũ�Ⱑ ū ����Ⱑ ���θ��� ���� ���� ���̶� ������ ���⿡ �Ź� bfs�� �̵� ��ġ�� Ž���ϱ�� ����.


�� ���� 3�� ���� �ȳ����� �ߴ��� - ���� ����� ũ�⵵ �������� �ʰ� �־���.!

*/

int main()
{
	int n; cin >> n;
	int size = 2; int count = 0; int answer = 0;
	vector<vector<int>> map_vec(n, vector<int>(n, 0));
	vector<vector<bool>> visited_vec(n, vector<bool>(n, false));
	priority_queue<tuple<int ,int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> nextPos_q; //�̵�Ƚ��, y, x
	tuple<int, int, int> pos;

	//�� �ʱ�ȭ
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map_vec[i][j];
			if (map_vec[i][j] == 9)
			{
				map_vec[i][j] = 0;
				pos = { 0,i,j };
			}
		}
	}

	nextPos_q.push(pos);
	while (!nextPos_q.empty())
	{
		int length = get<0>(nextPos_q.top());
		int y = get<1>(nextPos_q.top());
		int x = get<2>(nextPos_q.top());
		nextPos_q.pop();

		//�ߺ��� �����ϱ� ���� �湮 ���� ����
		if (y < 0 || x < 0 || y >= n || x >= n) continue;
		if (visited_vec[y][x] == true) continue;
		if (map_vec[y][x] > size)continue;
		else if (map_vec[y][x] == size) {}
		else if (map_vec[y][x] > 0)
		{
			++count;
			if (count == size)
			{
				size += 1;
				count = 0;
			}
			answer += length;
			length = 0;
			nextPos_q = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>();
			map_vec[y][x] = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					visited_vec[i][j] = false;
				}
			}
		}
		
		visited_vec[y][x] = true;

		nextPos_q.push(make_tuple(length+1, y + 1, x));
		nextPos_q.push(make_tuple(length + 1,y, x-1));
		nextPos_q.push(make_tuple(length + 1,y, x+1));
		nextPos_q.push(make_tuple(length + 1, y-1, x));
	}
	cout << answer;
}