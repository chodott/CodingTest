#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	vector<pair<long long, long long>> meeting_vec;
	while (n--)
	{
		long long start, end; cin >> start >> end;
		meeting_vec.emplace_back(make_pair(end, start));
	}
	
	sort(meeting_vec.begin(), meeting_vec.end());

	int count = 0; long long end = 0;
	for (auto& data : meeting_vec)
	{
		if (end <= data.second)
		{
			count++;
			end = data.first;
		}
	}

	cout << count << endl;
}