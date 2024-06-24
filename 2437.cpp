#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> chu_vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> chu_vec[i];
	}
	sort(chu_vec.begin(), chu_vec.end());
	int max =1;
	
	for (int i = 0; i < n; ++i)
	{
		if (max >= chu_vec[i]) max += chu_vec[i] ;
		else break;
	}
	cout << max;
}