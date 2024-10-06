#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> tree_vec;
	while (n--)
	{
		int tree; cin >> tree;
		tree_vec.emplace_back(tree);
	}
	sort(tree_vec.begin(), tree_vec.end());

	int start = 0; int end = tree_vec.back();
	int answer = 0;
	while (start <= end)
	{
		long long sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < tree_vec.size(); ++i)
		{
			if (tree_vec[i] <= mid) continue;
			sum += (tree_vec[i] - mid);
		}

		if (sum >= m)
		{
			answer = mid;
			start = mid + 1;
		}
		else end = mid - 1;
	}
	cout << answer;
}