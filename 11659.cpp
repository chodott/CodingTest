#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int n, m; cin >> n >> m;
	vector<int> num_vec{0};
	vector<int> sum_vec{0};
	int sum = 0;
	while (n--)
	{
		int num; cin >> num;
		num_vec.emplace_back(num);
		sum_vec.emplace_back(sum += num);
	}

	while (m--)
	{
		int start; int end; cin >> start >> end;
		cout << sum_vec[end] - sum_vec[start - 1] <<"\n";
	}
}