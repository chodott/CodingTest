#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n; cin >> n;
	int sum = 0;
	bool haveZero = false;
	priority_queue<int, vector<int>, less<int>> plus_pq;
	priority_queue<int,vector<int>, greater<int>> minus_pq;

	while (n--)
	{
		int num; cin >> num;
		if (num < 0) minus_pq.push(num);
		else if (num > 1) plus_pq.push(num);
		else
		{
			sum += num;
			if(num == 0) haveZero = true;
		}
	}

	int save = 0;
	while (!minus_pq.empty())
	{
		if (save == 0) save = minus_pq.top();
		else
		{
			sum += save * minus_pq.top();
			save = 0;
		}
		minus_pq.pop();
	}
	if(!haveZero) sum += save;
	save = 0;
	while (!plus_pq.empty())
	{
		if (save == 0) save = plus_pq.top();
		else
		{
			sum += save * plus_pq.top();
			save = 0;
		}
		plus_pq.pop();
	}
	sum += save;
	cout << sum;
}