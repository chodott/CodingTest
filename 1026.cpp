#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int answer = 0;
	vector<int> a_vec(n);
	vector<int> b_vec(n);
	for (int i = 0; i < n; ++i)  cin >> a_vec[i];
	for (int i = 0; i < n; ++i)  cin >> b_vec[i];
	sort(a_vec.begin(), a_vec.end(), greater<int>());
	sort(b_vec.begin(), b_vec.end(), less<int>());
	for (int i = 0; i < n; ++i) answer += (a_vec[i] * b_vec[i]);
	cout << answer;
}