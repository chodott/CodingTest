#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	long long solve[1001] = {0, 1,2 };
	for (int i = 3; i <= n; ++i)
	{
		solve[i] = (solve[i - 1] + solve[i - 2]) % 10007;
	}
	cout << solve[n];
}