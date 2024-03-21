#include <iostream>
#include <vector>
using namespace std;
int main()
{
	pair<int,int> leftright[1000];
	int n;
	cin >> n;
	fill(&leftright[0], &leftright[n + 1], make_pair(0,0));
	vector<int> n_vec(n);
	for (int i = 0; i < n; ++i) cin >> n_vec[i];
	int max = n_vec.size() - 1;
	//leftright[0] = { 1,0 }; leftright[max] = { 0,1 };
	for (int i = 0;  i < n_vec.size(); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (n_vec[i] > n_vec[j])
				leftright[i].first = leftright[i].first <= leftright[j].first ? leftright[j].first + 1 : leftright[i].first;

			if(n_vec[max - i] > n_vec[max-j])
				leftright[max-i].second = leftright[max - i].second <= leftright[max - j].second ? leftright[max - j].second + 1 : leftright[max - i].second;
		}
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int sum = leftright[i].first + leftright[i].second;
		answer = answer < sum ? sum : answer;
	}
	cout << answer+1;	//센터 값 포함
}