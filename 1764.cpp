#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n,m; cin >> n >> m;
	set<string> dontListen_set;
	set<string> dontListenLook_set;
	while (n--)
	{
		string name; cin >> name;
		dontListen_set.insert(name);
	}

	while (m--)
	{
		string name; cin >> name;
		if (dontListen_set.find(name) == dontListen_set.end()) continue;
		dontListenLook_set.insert(name);
	}
	cout << dontListenLook_set.size() << endl;;
	for (auto& s : dontListenLook_set) cout << s << endl;
}