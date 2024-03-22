#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> index_vec;
	int length[100];
	fill(&length[0], &length[99], 1);
	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		index_vec.emplace_back(make_pair(start, end));
	}
	sort(index_vec.begin(), index_vec.end());
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (index_vec[i].second > index_vec[j].second)
				length[i] = length[i] <= length[j] ? length[j] + 1 : length[i];
		}
	}
	
	int maxLength = 0;
	for (int i = 0; i < n; ++i)
		maxLength = maxLength < length[i] ? length[i] : maxLength;
	cout << n - maxLength;
}