#include <iostream>
#include <vector>

using namespace std;

//문제를 보니 dp가 즉시 떠올랐다. dp를 이용한 방식은 탐색 범위를 0에서 n-1까지 늘려가며 수열의 최대 길이를 찾아내는데, 
// 새로 반영하는 인덱스 i번째의 수가 현재 최장 수열의 가장 큰 수보다 작을 때 dp의 0~i-1까지 i번째 수보다 작은 값을 찾는 작업이 필요하다. 
//  따라서 이는 시간 복잡도가 O(N^2)를 가지게 되는데,  해당 문제는 수열의 길이가 최대 1000000이기에  반드시 시간초과가 날 것이라 판단했다.



int findIndex(vector<int>& dp, int num, int start, int end)
{
	if (start > end) return -1;

	int mid = (end + start) / 2;
	if (dp[mid] < num && num <= dp[mid + 1]) return mid + 1;
	else if (mid == 0 && dp[mid] >= num) return mid;
	if(dp[mid] < num) return findIndex(dp, num, mid + 1, end);
	else	return findIndex(dp, num, start, mid);
}

int main()
{
	int n; cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<int> num_vec(n);
	vector<int> dp;
	for (int i = 0; i < n; ++i) cin >> num_vec[i];
	dp.emplace_back(num_vec[0]);
	for (int i = 1; i < n; ++i)
	{
		int value = num_vec[i];
		if (value > dp[dp.size() - 1]) dp.emplace_back(value);
		else
		{
			int index = findIndex(dp, value, 0, dp.size() - 1);
			dp[index] = value;
		}
	}
	cout << dp.size();
	
}