#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n;
	int count[1000000+1];
	cin >> n;
	vector<int> data(n, 0);
	vector<int> answer(n,-1);
	stack<int> wait_stack;
	fill(&count[0], &count[1000001], 0);
	for(int i=0; i<n;++i )
	{
		int num;
		cin >> num;
		count[num]++;
		data[i] = num;
	}

	for (int i = 0; i < n; ++i)
	{
		while (!wait_stack.empty() && count[data[wait_stack.top()]] < count[data[i]])
		{
			answer[wait_stack.top()] = data[i];
			wait_stack.pop();
		}
		wait_stack.push(i);
	}

	for (int i : answer) cout << i << " ";

}