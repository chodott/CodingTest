#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare
{
	bool operator () (pair<long long, long long>p1, pair<long long, long long> p2)
	{
		if (p1.first == p2.first)
			return p1.second < p2.second;

		return p1.first > p2.first;
	}
};

int main()
{
	int n;
	long long m;
	cin >> n >> m;
	priority_queue <pair<long long, long long>, vector<pair<long long,long long>>,
		compare>pq;
	long long answer = m;
	for (int i = 0; i < n; ++i)
	{
		long long start, end;
		cin >> start >> end;
		if (end >= start) continue;
		pq.push(make_pair(end, start));
	}

	long long endPos = pq.top().first;
	long long startPos = pq.top().second;
	pq.pop();
	while (!pq.empty())
	{
		long long end = pq.top().first;
		long long start = pq.top().second;
		pq.pop();
		if (startPos < end)
		{
			answer += (startPos - endPos) * 2;
			startPos = start;
			endPos = end;
			continue;
		}
		startPos = max(startPos, start);
		cout << startPos << " " << endPos << endl;
	}
	answer += (startPos - endPos) * 2;
	cout << answer;
}