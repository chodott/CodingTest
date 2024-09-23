#include <iostream>

using namespace std;

int main()
{
	string s; cin >> s;

	int length = s.length();
	bool bAllSame = true;
	for (int i = 0; i < length/2; ++i)
	{
		if (s[i] != s[length - i - 1])
		{
			cout << length;
			return 0;
		}
		else if (s[i] != s[i+1]) bAllSame = false;
	}

	if (bAllSame) cout <<  - 1;
	else cout << length - 1;
}