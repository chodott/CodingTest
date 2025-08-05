#include <iostream>
using namespace std;
int lcs[1001][1001];

void research(const string& s1, const string& s2)
{
	string answer;
	int i = s1.length();
	int j = s2.length();
	while (i >= 1 && j >= 1)
	{
		if (lcs[i][j] == lcs[i - 1][j])
		{
			i--;
		}
		else if (lcs[i][j] == lcs[i][j - 1])
		{
			j--;
		}
		else
		{
			answer += s1[i - 1];
			i--; j--;
		}
	}

	for (int index = answer.length() - 1; index >= 0; --index)
	{
		cout << answer[index];
	}

}
int main()
{
	string s1,s2; cin >> s1>>s2;

	for (int i = 1; i <= s1.length(); ++i)
	{
		for (int j = 1; j <= s2.length(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	int value = lcs[s1.length()][s2.length()];
	cout << value << "\n";
	if (value != 0)
	{
		research(s1, s2);
	}
}