#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;	cin >> t;
	while (t--)
	{
		vector<string> num_vec;
		string command, data;
		int length;
		cin >> command >> length>>data;
		data = data.substr(1, data.size() - 2);
		stringstream ss(data);
		string buffer;
		while (getline(ss, buffer, ','))
		{
			num_vec.emplace_back(buffer);
		}

		bool bReverse = false;
		int startPos = 0;
		int endPos = 0;
		for (int i = 0; i < command.length(); ++i)
		{
			if (command[i] == 'R') bReverse = !bReverse;
			else
			{
				if (bReverse) endPos++;
				else startPos++;
			}
		}
		int deleteSize = endPos + startPos;

		if (num_vec.size() < deleteSize) cout << "error" << endl;
		else if (num_vec.size() == deleteSize) cout << "[]" << endl;
		else
		{
			cout << "[";
			endPos = num_vec.size() - endPos-1;
			if (bReverse)
			{
				for (int i = endPos; i > startPos; --i) 
					cout << num_vec[i] << ",";
				cout << num_vec[startPos];
			}
			else
			{
				for (int i = startPos; i < endPos; ++i)
					cout << num_vec[i] << ",";
				cout << num_vec[endPos];
			}
			cout << "]"<<endl;
		}
	}
}