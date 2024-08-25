#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	long sum = 0;
	vector<pair<int, int>> jewel_vec;
	priority_queue<int, vector<int>, greater<int>> bag_pq;
	priority_queue<int> value_pq;
	cin >> n >> k;
	while (n--)
	{
		int m, v;
		cin >> m >> v;
		jewel_vec.emplace_back(make_pair(m, v));
	}
	while (k--)
	{
		int weight; cin >> weight;
		bag_pq.push(weight);
	}
	
	sort(jewel_vec.begin(), jewel_vec.end());

	int index = 0;
	while (!bag_pq.empty())
	{
		int weight = bag_pq.top();
		bag_pq.pop();

		while (index < jewel_vec.size())
		{
			if (jewel_vec[index].first > weight) break;
			value_pq.push(jewel_vec[index].second);
			index++;
		}

		//담을 수 있을게 없을 때!
		if (value_pq.empty()) continue;
		sum += value_pq.top();
		value_pq.pop();
	}

	cout << sum;
}