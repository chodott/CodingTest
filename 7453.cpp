#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& sum_vec, int target, int start, int end, bool bGreater)
{
	if (start == end)
	{
		if (target == sum_vec[start]) return start;
		else return -1;
	}
	int mid = (start + end) / 2;
	int a = -1; int b = -1;
	if (bGreater)
	{
		if (sum_vec[mid+1] <= target) a = binary_search(sum_vec, target, mid+1, end, bGreater);
		else b = binary_search(sum_vec, target, start, mid, bGreater);
	}
	else
	{
		if (sum_vec[mid] >= target) a = binary_search(sum_vec, target, start, mid, bGreater);
		else b = binary_search(sum_vec, target, mid + 1, end, bGreater);
	}
	
	if (a == -1 && b == -1) return -1;
	else if (a == -1) return b;
	else if (b == -1) return a;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<vector<int>> num_vec(4, vector<int>(n, 0));
	vector<vector<int>> sum_vec(2, vector<int>());


	for(int i=0;i<n;++i)
	{
		for (int j = 0; j < 4; ++j) cin >> num_vec[j][i];
		for (int j = 0; j < i; ++j)
		{
			sum_vec[0].emplace_back(num_vec[0][j] + num_vec[1][i]);
			sum_vec[0].emplace_back(num_vec[1][j] + num_vec[0][i]);

			sum_vec[1].emplace_back(num_vec[2][j] + num_vec[3][i]);
			sum_vec[1].emplace_back(num_vec[3][j] + num_vec[2][i]);
		}
		sum_vec[0].emplace_back(num_vec[0][i] + num_vec[1][i]);
		sum_vec[1].emplace_back(num_vec[2][i] + num_vec[3][i]);
	}
	sort(sum_vec[0].begin(), sum_vec[0].end());
	sort(sum_vec[1].begin(), sum_vec[1].end());
	long long answer = 0;
	
	for (int sum : sum_vec[0])
	{
		int value = sum * -1;
		int startIdx = binary_search(sum_vec[1], value, 0, sum_vec[1].size() - 1, false);
		int endIdx = binary_search(sum_vec[1], value, 0, sum_vec[1].size() - 1, true);
		if (-1 == startIdx || -1 == endIdx) continue;
		answer += (endIdx - startIdx + 1);
	}
	cout << answer;
}