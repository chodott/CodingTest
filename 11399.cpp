#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; int answer = 0;
	vector<int> time_vec;
	cin >> n;
	while (n--)
	{
		int time; cin >> time;
		time_vec.emplace_back(time);
	}
	sort(time_vec.begin(), time_vec.end(), greater<int>());

	for (int i = 0; i < time_vec.size(); ++i)
		answer += time_vec[i] * (i + 1);

	cout << answer;
}