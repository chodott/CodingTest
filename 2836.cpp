#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m; cin >> n >> m;
	long long length = 0;
	vector<pair<long long, long long>> route_vec;
	while (n--)
	{
		long long start; long long end;
		cin >> start >> end;
		if (start <= end) continue;
		route_vec.emplace_back(make_pair(end, start));
	}
	sort(route_vec.begin(), route_vec.end());

	pair<long long, long long> max_route = { 0,0 };
	for (auto& route : route_vec)
	{
		if (max_route.second < route.first)
		{
			length += (max_route.second - max_route.first);
			max_route.first = route.first;
		}
		if (max_route.second < route.second) 
			max_route.second = route.second;
	}
	length += (max_route.second - max_route.first);
	length *= 2;
	length += m;
	cout << length;
}

//struct compare
//{
//	bool operator () (pair<long long, long long>p1, pair<long long, long long> p2)
//	{
//		if (p1.first == p2.first)
//			return p1.second < p2.second;
//
//		return p1.first > p2.first;
//	}
//};
//
//int main()
//{
//	int n;
//	long long m;
//	cin >> n >> m;
//	priority_queue <pair<long long, long long>, vector<pair<long long,long long>>,
//		compare>pq;
//	long long answer = m;
//	for (int i = 0; i < n; ++i)
//	{
//		long long start, end;
//		cin >> start >> end;
//		if (end >= start) continue;
//		pq.push(make_pair(end, start));
//	}
//
//	long long endPos = pq.top().first;
//	long long startPos = pq.top().second;
//	pq.pop();
//	while (!pq.empty())
//	{
//		long long end = pq.top().first;
//		long long start = pq.top().second;
//		pq.pop();
//		if (startPos < end)
//		{
//			answer += (startPos - endPos) * 2;
//			startPos = start;
//			endPos = end;
//			continue;
//		}
//		startPos = max(startPos, start);
//	}
//	answer += (startPos - endPos) * 2;
//	cout << answer;
//}