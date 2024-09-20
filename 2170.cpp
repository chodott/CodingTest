#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long length = 0;
	vector<pair<int, int>> line_vec;
	int n; cin >> n;
	while (n--)
	{
		int start, end; cin >> start >> end;
		line_vec.emplace_back(make_pair(start,end));
	}

	sort(line_vec.begin(), line_vec.end());

	int start=-1000000001;
	int end= -1000000001;

	for (auto& line : line_vec)
	{
		if (end < line.first)
		{
			length += (long long)(end - start);
			start = line.first;
		}

		if (end < line.second)
		{
			end = line.second;
		}
	}
	length += (long long)(end - start);
	cout << length;

}