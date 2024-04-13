#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findRoot(vector<int>& root_vec, int i)
{
	if (i == root_vec[i]) return i;
	else return root_vec[i] = findRoot(root_vec, root_vec[i]);
}

int merge(vector<int>& root_vec ,vector<int>& weight_vec, int a, int b)
{
	int root_a = findRoot(root_vec, a);
	int  root_b = findRoot(root_vec, b);
	int weight = weight_vec[root_a];
	if (root_a != root_b)
	{
		weight += weight_vec[root_b];

		root_vec[root_b] = root_a;
		weight_vec[root_a] = weight;

	}
	return weight;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int caseCount;
	cin >> caseCount;
	while (caseCount > 0)
	{
		map<string, int> index_map;
		caseCount --;
		int cnt = 0;
		int f;
		string a, b;
		cin >> f;
		vector<int> weight_vec(200002, 1);
		vector<int> root_vec(200002,0);

		for (int i = 0; i < f; ++i)
		{
			cin >> a >> b;
			if (index_map[a] == 0)
			{
				index_map[a] = ++cnt;
				root_vec[cnt] = cnt;
			}
			if (index_map[b] == 0)
			{
				index_map[b] = ++cnt;
				root_vec[cnt] = cnt;
			}
			int weight = merge(root_vec, weight_vec, index_map[a], index_map[b]);
			cout << weight <<"\n";
		}
	}
}