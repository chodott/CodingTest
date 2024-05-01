#include <iostream>
#include <vector>
using namespace std;

int getRoot(vector<int>& root_vec, int num)
{
	if (num == root_vec[num]) return num;
	else return root_vec[num] = getRoot(root_vec, root_vec[num]);
}

bool bCanCycle(vector<int>& root_vec, int a, int b)
{
	int a_root = getRoot(root_vec, a);
	int b_root = getRoot(root_vec, b);
	if (a_root == b_root) return true;
	else
	{
		root_vec[b_root] = a_root;
		return false;
	}
}

int main()
{
	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<int> root_vec;
	for (int i = 0; i < n; ++i) root_vec.emplace_back(i);

	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (bCanCycle(root_vec, a, b) == true)
		{
			answer = i;
			break;
		}
	}
	cout << answer;
}