#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	vector<string> poke_vec(n+1);
	map<string, int> poke_map;

	for (int i = 1; i <= n; ++i)
	{
		cin >> poke_vec[i];
		poke_map.insert(make_pair(poke_vec[i], i));
	}
	while (m--)
	{
		string question;
		cin >> question;
		if (isdigit(question[0])) cout << poke_vec[stoi(question)] << "\n";
		else cout << poke_map[question] << "\n";
	}
}