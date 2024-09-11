#include <iostream>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;

		int cnt = 0;
		for (char c : s)
		{
			if (c == '(') cnt++;
			else
			{
				if (cnt == 0)
				{
					cnt = -1;
					break;
				}
				cnt--;
			}
		}
		if (cnt == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}