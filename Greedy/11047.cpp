#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	int answer = 0;
	cin >> n >> k;
	vector<int> coin_vec;
	for(int i=0;i<n;++i)
	{
		int coin; cin >> coin;
		coin_vec.emplace_back(coin);
	}

	for (int i = n - 1; i >= 0; --i)
		if (k >= coin_vec[i])
		{
			answer += k / coin_vec[i];
			k %= coin_vec[i];

			if (k == 0) break;
		}
	}
	cout << answer;
}