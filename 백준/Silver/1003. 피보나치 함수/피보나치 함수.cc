#include <iostream>

using namespace std;

pair<int, int> arr[41] = { {1,0}, {0,1} };

int main()
{
	int t; cin >> t;


	for (int i = 2; i <= 40; ++i)
	{
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}

	while (t--)
	{
		int n; cin >> n;

		cout << arr[n].first << " " << arr[n].second << "\n";

	}
}