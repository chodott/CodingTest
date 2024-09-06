#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	
	while (s.length() < t.length())
	{
		if (t.back() == 'B')
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else t.pop_back();
	}
	
	cout << (s == t);
}