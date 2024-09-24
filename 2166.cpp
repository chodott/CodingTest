#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<pair<double, double>> point_vec;
	double extent = 0;
	while (n--)
	{
		double x; double y; cin >> x >> y;
		point_vec.emplace_back(make_pair(x, y));
	}

	for (int i = 1; i < point_vec.size(); ++i)
	{
		extent += point_vec[i].second * point_vec[i - 1].first;
		extent -= point_vec[i].first * point_vec[i - 1].second;
	}
	extent += point_vec.back().first * point_vec.front().second;
	extent -= point_vec.back().second * point_vec.front().first;

	cout.precision(1);
	cout << fixed;
	cout << abs(extent / 2);
	
}