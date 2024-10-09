#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int l, c; cin >> l >> c;
	vector<char> char_vec(c);
	vector<bool> temp_vec(c);
	for(int i = 0; i < c;++i)
	{
		cin >> char_vec[i];
	}
	sort(char_vec.begin(), char_vec.end());

	for (int i = 0; i < l; ++i) temp_vec[i] = true;
	do
	{
		string answer = "";
		int vowelCnt = 0;
		int consonantCnt = 0;
		for (int i = 0; i < c; ++i)
		{
			if (temp_vec[i])
			{
				char ch = char_vec[i];
				answer += ch;
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowelCnt++;
				else consonantCnt++;
			}
		}
		if (vowelCnt >= 1 && consonantCnt >= 2)
			cout << answer << '\n';
	} while (prev_permutation(temp_vec.begin(), temp_vec.end()));
}