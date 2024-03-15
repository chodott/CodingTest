#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	vector<int> vec;
	cin >> n;
	int left = 0; int right = n - 1;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		vec.emplace_back(temp);
	}
	pair<int, int> answer = { vec[left],vec[right]};
	while (left < right)
	{
		int a = vec[left]; int b = vec[right];
		answer = (abs(answer.first + answer.second) >= abs(a + b)) ? make_pair(a, b) : answer;
		if (abs(a) < abs(b)) right--;
		else left++;
	}
	cout << answer.first << " " << answer.second;
}