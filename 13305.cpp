#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n; long long answer = 0;
	cin >> n;
	vector<int> length_vec(n-1,0);
	vector<long long> value_vec(n,0);

	for (int i = 0; i < n-1 ; ++i) cin >> length_vec[i];
	for (int i = 0; i < n ; ++i) cin >> value_vec[i];
	int pos = 0;
	
	for (int i = 0; i < length_vec.size(); ++i)
	{
		if (value_vec[pos] > value_vec[i]) pos = i;
		answer += value_vec[pos] * length_vec[i];
	}
	cout << answer;
}