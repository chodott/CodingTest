#include <iostream>

using namespace std;

int checkPalindrome(int start, int end, int result, string& str)
{
	while (start <= end)
	{
		if (str[start++] == str[end--]) continue;
		if (result == 1)
		{
			return 2;
		}

		result = min(checkPalindrome(start, end + 1, 1, str) ,checkPalindrome(start - 1, end, 1, str));
		return result;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		string str; cin >> str;
		int start = 0; int end = str.length() - 1;
		int result = 0;
		result = checkPalindrome(start, end, result, str);
		cout << result << "\n";
	}
}