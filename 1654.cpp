#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,n; cin >>k	>> n;
	vector<int> cable_vec;
	int top = 0;
	while (k--)
	{
		int length; cin >> length;
		cable_vec.emplace_back(length);
		top = max(top, length);
	}
	int answer = 0;
	long start = 1; long end = top;

	while (start <= end)
	{
		int cnt = 0;
		long mid = (start + end) / 2;
		for (auto& cable : cable_vec)
		{
			cnt += (cable/ mid);
		}

		if (cnt >= n)
		{
			answer = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << answer;
 }