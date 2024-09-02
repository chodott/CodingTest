#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Trie
{
public:
	map<char, Trie*> child_map;
	string cp = "";
	bool insert(string s)
	{
		Trie* curNode = this;
		bool bMakeNew = false;
		for (char c : s)
		{
			if (curNode->child_map.find(c) == curNode->child_map.end())
			{
				curNode->child_map[c] = new Trie();
				bMakeNew = true;
			}
			curNode = curNode->child_map[c];
			if (!curNode->cp.empty()) return false;
		}
		curNode->cp = s;
		return bMakeNew;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		Trie* root = new Trie();
		bool result = true;
		while (n--)
		{
			string cp; cin >> cp;
			if (result == false) continue;
			result = root->insert(cp);
		}
		if (result) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}