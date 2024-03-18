#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combine(int index, int max, long sum, vector<long long>& tool_vec, vector<long long>& sum_vec)
{
	if (index == max)
	{
		sum_vec.emplace_back(sum);
		return;
	}
	combine(index + 1, max, sum, tool_vec, sum_vec);		//반영
	combine(index + 1, max, sum + tool_vec[index], tool_vec, sum_vec);	//미반영
}

int main()
{

	int n, c;
	int answer = 0;
	vector<long long> tool_vec;
	vector<long long> left_vec;
	vector<long long> right_vec;
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		long long tool;
		cin >> tool;
		tool_vec.emplace_back(tool);
	}
	
	combine(0, n / 2, 0, tool_vec, left_vec);
	combine(n / 2, n, 0, tool_vec, right_vec);

	sort(left_vec.begin(), left_vec.end());

	for (int i = 0; i < right_vec.size(); ++i)
	{
		answer += upper_bound(left_vec.begin(), left_vec.end(), c - right_vec[i]) - left_vec.begin();
	}
	cout << answer;
}