#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<pair<int,int>> num_queue;
	stack<pair<int,int>> wait_stack;
	vector<int> rbn_vec(n, -1);
	for(int i=0; i< n;++i)
	{
		int num;
		cin >> num;
		num_queue.push(make_pair(i, num));
	}

	while (!num_queue.empty())
	{
		int num = num_queue.front().second;
		while (!wait_stack.empty())
		{
			int index = wait_stack.top().first;
			int target = wait_stack.top().second;
			if (target < num)
			{
				rbn_vec[index] = num;
				wait_stack.pop();
				continue;
			}
			else break;
		}
		wait_stack.push(num_queue.front());
		num_queue.pop();
	}

	for (int n : rbn_vec) cout << n << " ";

}