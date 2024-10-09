#include <iostream>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		int result = 1;
		int r = 1;
		for (int i = m; i - n > 0; --i)
		{
			result *= i;
			result /= r++;
		}
		cout << result << "\n";
	}
}