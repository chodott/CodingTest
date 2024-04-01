#include <stdio.h>
#include <vector>
using namespace std;

int findRoot(vector<int>& union_set, int a)
{
	if (union_set[a] == a)
		return a;
	else return union_set[a] = findRoot(union_set, union_set[a]);
}
void merge(vector<int>&union_set, int a, int b)
{
	int a_root, b_root;
	a_root = findRoot(union_set, a);
	b_root = findRoot(union_set, b);
	if (a_root == b_root) return;
	union_set[b_root] = a_root;
}

int main()
{
	int n, m;
	int cmd, a, b;
	scanf("%d %d", &n, &m);
	vector<int> union_set;
	for (int i = 0; i <= n; ++i) union_set.emplace_back(i);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &cmd, &a,&b);
		switch (cmd)
		{
		case 0:
			merge(union_set, a, b);
			break;
		case 1:
			if (findRoot(union_set, a) == findRoot(union_set, b)) printf("yes\n");
			else printf("no\n");
			break;
		}
	}

}