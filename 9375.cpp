#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		map<string, int> categoryCnt_map;
		int n; cin >> n;
		int answer = 1;
		while (n--)
		{
			string s, category; cin >> s>>category;
			if (categoryCnt_map.find(category) == categoryCnt_map.end())
				categoryCnt_map[category] = 1;
			categoryCnt_map[category]++;
		}

		for (auto& data : categoryCnt_map)
			answer *= data.second;
		cout << answer-1 << endl;
	}
}