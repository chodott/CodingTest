#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		int k; cin >> k;
		if (k == 0) break;
		vector<int> num_vec(k);
		vector<bool> temp_vec(k);
		for (int i = 0; i < k; ++i) cin >> num_vec[i];
		fill(temp_vec.begin(), temp_vec.begin() +6, true);

		do
		{
			for (int i = 0; i < k; ++i)
			{
				if (temp_vec[i]) cout << num_vec[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(temp_vec.begin(), temp_vec.end()));
		cout << "\n";
	}
}