#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int requiredTime[MAX + 1];
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> next_q;
	fill(&requiredTime[0], &requiredTime[MAX + 1], MAX);

	next_q.push(make_pair(0, n));

	while (!next_q.empty())
	{
		int value = next_q.top().first;
		int pos = next_q.top().second;
		next_q.pop();

		if (pos < 0 || pos >MAX) continue;
		if (requiredTime[pos] <= value) continue;

		requiredTime[pos] = value;
		if (pos == k) break;

		if(pos != 0) next_q.push(make_pair(value, 2 * pos));
		next_q.push(make_pair(value+1, pos + 1));
		next_q.push(make_pair(value+1, pos - 1));
	}

	cout << requiredTime[k];
}