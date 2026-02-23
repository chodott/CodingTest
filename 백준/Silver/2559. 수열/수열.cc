#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int leftSum = accumulate(arr.begin(), arr.begin() + k, 0);
	int leftAnswer = leftSum;
	pair<int, int> leftPos = { 0, k - 1 };

	for (int i = 0; i < n - k; ++i)
	{
		leftSum -= arr[leftPos.first++];
		leftSum += arr[++leftPos.second];
		leftAnswer = max(leftAnswer, leftSum);
	}
	cout << leftAnswer;
}