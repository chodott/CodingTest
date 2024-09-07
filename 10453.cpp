#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s1, s2; cin >> s1 >> s2;
		int count1=0, count2=0;
		int swapCnt = 0;
		bool bCantChange = false;
		if (s1.length() != s2.length())
		{
			cout << -1<<endl;
			continue;
		}

		for (int i = 0; i < s1.length(); ++i)
		{
			if (s1[i] == s2[i]) continue;
			char target = s2[i];
			int index = i+1;
			while (s1[index] != target)
			{
				if (index >= s1.length()) break;
				index++;
			}
			if (index >= s1.length())
			{
				bCantChange = true;
				break;
			}
			while (index != i)
			{
				swap(s1[index - 1], s1[index]);
				index--;
				swapCnt++;
			}

		}
		if (bCantChange) continue;
		else cout << swapCnt << endl;

	}
}