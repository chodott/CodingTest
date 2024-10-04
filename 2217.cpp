#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> lope_vec(n);
	for (int i = 0; i < n; ++i) cin >> lope_vec[i];
	sort(lope_vec.begin(), lope_vec.end());
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer = max(answer, lope_vec[i] * (n - i ));
	}
	cout << answer;
}