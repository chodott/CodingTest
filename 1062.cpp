#include <iostream>

using namespace std;

int main()
{
	int x; cin >> x;
	int answer = 0;
	while (x)
	{
		if (x % 2 == 1) answer += 1;
		x /= 2;
	}
	cout << answer;
}