#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	vector<priority_queue<int, vector<int>, greater<int>>> index_pqs(10);
	cin >> n >> k;
	string num_string;
	string answer;
	int length = n - k;
	cin >> num_string;
	for (int i = 0; i < num_string.length(); ++i)
	{
		int num = num_string[i] - '0';
		index_pqs[num].push(i);
	}

	int index = 0;
	while (index < num_string.size())
	{
		int num = num_string[index] - '0';
		for (int i = 9; i > num; --i)
		{
			while (!index_pqs[i].empty())
			{
				if (index_pqs[i].top() > index)
					break;
				
				index_pqs[i].pop();
			}

			if (index_pqs[i].empty()) continue;
			int nextIndex = index_pqs[i].top();
			int gap = nextIndex - index;
			if (gap <= k)
			{
				index = nextIndex;
				k -= gap;
				break;
			}
		}
		answer += num_string[index];
		index++;
	}
	
	answer += num_string.substr(index);
	cout << answer.substr(0, length);
}