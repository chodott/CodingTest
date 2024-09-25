#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<bool> exist_vec(21, false);
	int m; cin >> m;
	while (m--)
	{
		string command; int num;
		cin >> command;
		if (command == "all") exist_vec = vector<bool>(21, true);
		else if(command == "empty") exist_vec = vector<bool>(21, false);
		else
		{
			cin >> num;
			if (command == "add") exist_vec[num] = true;
			else if (command == "remove") exist_vec[num] = false;
			else if (command == "check") cout << exist_vec[num] << "\n";
			else if (command == "toggle") exist_vec[num] = !exist_vec[num];

		}
	}

}