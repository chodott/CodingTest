#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int leftSum = accumulate(arr.begin(), arr.begin() + k, 0);
	int rightSum = accumulate(arr.end() - k, arr.end(), 0);
	int leftAnswer = leftSum;
	int rightAnswer = rightSum;
	pair<int, int> leftPos = { 0, k - 1 };
	pair<int, int> rightPos = { n - k, n - 1 };

	for (int i = 0; i < (n - k)/2; ++i)
	{
		leftSum -= arr[leftPos.first++];
		leftSum += arr[++leftPos.second];

		rightSum -= arr[rightPos.second--];
		rightSum += arr[--rightPos.first];

		leftAnswer = max(leftAnswer, leftSum);
		rightAnswer = max(rightAnswer, rightSum);
	}
	cout << max(leftAnswer, rightAnswer);
}