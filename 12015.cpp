#include <iostream>
#include <vector>

using namespace std;

//������ ���� dp�� ��� ���ö���. dp�� �̿��� ����� Ž�� ������ 0���� n-1���� �÷����� ������ �ִ� ���̸� ã�Ƴ��µ�, 
// ���� �ݿ��ϴ� �ε��� i��°�� ���� ���� ���� ������ ���� ū ������ ���� �� dp�� 0~i-1���� i��° ������ ���� ���� ã�� �۾��� �ʿ��ϴ�. 
//  ���� �̴� �ð� ���⵵�� O(N^2)�� ������ �Ǵµ�,  �ش� ������ ������ ���̰� �ִ� 1000000�̱⿡  �ݵ�� �ð��ʰ��� �� ���̶� �Ǵ��ߴ�.



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