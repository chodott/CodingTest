#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> tower_vec(n+1);
	vector<int> answer_vec(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> tower_vec[i];

	for (int i = 1; i <= n; ++i)
	{
		int height = tower_vec[i];
		int next = i - 1;
		while (next > 0)
		{
			if (height < tower_vec[next]) break;
			next = answer_vec[next];
		}
		if (next <= 0) answer_vec[i] = 0;
		else answer_vec[i] = next;
		cout << answer_vec[i] << " ";
	}
}