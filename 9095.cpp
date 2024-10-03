#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int sum[12] = {0, 1,2,4 };
	for (int i = 4; i < 11; ++i)
	{
		sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
	}
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << sum[n]<<"\n";
	}
}