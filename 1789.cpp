#include <iostream>

using namespace std;

int main()
{
	unsigned int s; cin >> s;
	int answer = 0;
	unsigned int sum = 0;
	unsigned int num = 1;
	while (s-sum >=num)
	{
		sum += num++;
		answer++;
	}
	cout << answer;
}