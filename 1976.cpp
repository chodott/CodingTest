#include <iostream>
#include <vector>
using namespace std;

int findRoot(vector<int>& root_vec, int a)
{
	int value = root_vec[a];
	if (value == a) return a;
	else return root_vec[a] = findRoot(root_vec, value);
}

void mergeRoot(vector<int>& root_vec, int a, int b)
{
	int a_root = findRoot(root_vec, a);
	int b_root = findRoot(root_vec,  b);
	if (a == b) return;
	if (a < b) root_vec[b_root] = a_root;
	else root_vec[a_root] = b_root;
}


int main()
{
	int n, m;
	bool connected;
	vector<int> root_vec;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) root_vec.emplace_back(i);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> connected;
			if (connected == true)
			{
				mergeRoot(root_vec, i, j);
			}
		}
	}

	int num;
	int prevRoot =0;
	bool bTrue = true;;
	for (int i = 0; i < m; ++i)
	{
		cin >> num;
		int root = findRoot(root_vec, num);
		if (root != prevRoot && i != 0)
		{
			bTrue = false;
			break;
		}
		prevRoot = root;
	}
	if (bTrue) cout << "YES";
	else cout << "NO";
}