#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct compare_pq
{
	bool operator () (pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.first == p2.first)
			return p1.second > p2.second;
		return p1.first > p2.first;
	}
};

bool compare_vec(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<pair<int,int>> class_vec;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> class_pq;
	priority_queue<int, vector<int>, greater<int>> end_pq;
	while (n--)
	{
		int s, t; cin >> s >> t;
		class_vec.emplace_back(make_pair(s, t));
		class_pq.push(make_pair(s, t));
	}

	//벡터 오름차순 정렬
	sort(class_vec.begin(), class_vec.end(), less<pair<int,int>>());
	end_pq.push(class_vec[0].second);
	for(int i=1;i<class_vec.size(); ++i)
	{

		int start = class_vec[i].first;
		int end = class_vec[i].second;

		if (end_pq.top() <= start) end_pq.pop();
		end_pq.push(end);
		
	}

	////PQ 오름차순 정렬
	//end_pq.push(class_pq.top().second);
	//class_pq.pop();

	//while (!class_pq.empty())
	//{
	//	int start = class_pq.top().first;
	//	int end = class_pq.top().second;
	//	class_pq.pop();

	//	if (end_pq.top() <= start) end_pq.pop();
	//	end_pq.push(end);
	//}

	cout << end_pq.size();
}