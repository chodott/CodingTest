#include <iostream>

using namespace std;

int main()
{
	int start, goal; cin >> start >> goal;
	int answer = 0;
	while (goal !=start)
	{
		if (goal < start)
		{
			cout << -1; return 0;
		}
		if (goal % 2 == 0) goal /= 2;
		else
		{
			int end = goal % 10;
			if (end == 1) goal /= 10;
			else
			{
				cout << -1; return 0;
			}
		}
		answer++;
	}
	cout << answer + 1;
 }