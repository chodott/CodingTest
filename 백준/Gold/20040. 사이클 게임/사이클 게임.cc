#include <iostream>
#include <vector>
using namespace std;

int findParrent(vector<int>& vec, int target)
{
	if (target == vec[target])
	{
		return target;
	}

	return vec[target] = findParrent(vec, vec[target]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> parent_vec;
	for (int i = 0; i <= n; ++i)
	{
		parent_vec.emplace_back(i);
	}
	int answer = 0;
	
	for(int i=0;i<m;++i)
	{
		int a, b; cin >> a >> b;
		int parentA = findParrent(parent_vec, a);
		int parentB = findParrent(parent_vec, b);
		if (parentA == parentB && answer == 0)
		{
			answer = i+1;
		}
		if (parentA < parentB)
		{
			parent_vec[parentB] = parentA;
		}
		else
		{
			parent_vec[parentA] = parentB;
		}
	}
	cout << answer;
}