#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000
//공평한 거리?

int main()
{
	int n, c;
	int answer = INF;
	cin >> n >> c;
	vector<int> pos_vec;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		pos_vec.emplace_back(x);
	}
	sort(pos_vec.begin(), pos_vec.end());

	int cnt = c-1;
	int start = 0; int end = pos_vec[n - 1] - pos_vec[0];
	while (start <= end)
	{
		answer = INF;
		cnt = c - 1;
		int gap = (end + start) / 2;
		int prev = 0;
		for (int i = 1; i < n; ++i)
		{
			int distance = pos_vec[i] - pos_vec[prev];
			if (distance < gap) continue;
			prev = i;
			cnt--;
			answer = min(distance, answer);
		}
		if (cnt <= 0) start = gap + 1;
		else end = gap - 1;
	}

	cout << answer;
}