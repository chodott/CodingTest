#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int lastChicken_vec[13]; 
pair<int, int> house_vec[100];
pair<int,int> chicken_vec[13];
int answer = INF;
int n; int m;
int houseCnt; int chickenCnt;

void combination(int index, int count)
{
	if (count == m)
	{
		int distance = 0;
		for (int i=0;i<houseCnt;++i)
		{
			int minDist = INF;
			for (int j=0;j<m;++j)
			{
				minDist = min(minDist, abs(chicken_vec[lastChicken_vec[j]].first - house_vec[i].first) + abs(chicken_vec[lastChicken_vec[j]].second - house_vec[i].second));
			}
			distance += minDist;
		}
		answer = min(answer, distance);
		return;
	}

	else
	{
		for (int i = index; i <= n - (m - count); ++i)
		{
			lastChicken_vec[count] = i;
			combination(i + 1, count + 1);
		}
	}
}

int main()
{
	cin >> n>>m;
	//데이터 초기화
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int value; cin >> value;
			if (value == 2) chicken_vec[chickenCnt++] = { i,j };
			else if (value == 1) house_vec[houseCnt++] = { i,j };
		}
	}

	combination(0, 0);

	cout << answer;
}