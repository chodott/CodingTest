#include <iostream>
#include <vector>
using namespace std;

long long makeTree(long long data[], vector<long long>& tree, int start, int end, int index)
{
	if (start == end) return tree[index] = data[start];
	int mid = (start + end) / 2;

	return tree[index] = makeTree(data, tree, start, mid, index * 2) +
		makeTree(data, tree, mid + 1, end, index * 2 + 1);
}

void updateTree(long long data[], vector<long long>& tree, int start, int end,
							int index,	int target, long long value)
{
	if (target > end || target < start) return;
	
	tree[index] += value;
	if (start == end) return;
	int mid = (start + end) / 2;
	updateTree(data, tree, start, mid, index * 2, target, value);
	updateTree(data, tree, mid + 1, end, index * 2 + 1, target, value);	
}

long long returnSum(vector<long long>& tree, int start, int end, int index, int startPos, int endPos)
{
	if (start > endPos || end < startPos) return 0;
	if (start >= startPos && endPos >= end) return tree[index];
	int mid = (start + end) / 2;
	return returnSum(tree, start, mid, index * 2, startPos, endPos) +
		returnSum(tree, mid + 1, end, index*2 + 1, startPos, endPos);
}

int main()
{
	int n, m,k;
	long long data[1000000];
	cin >> n >> m>>k;
	vector<long long> tree(n * 4 + 1, 0);
	for (int i = 0; i < n; ++i) cin >> data[i];
	makeTree(data, tree, 0, n-1, 1);
	for (int i = 0; i < m + k; ++i)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;
		b -= 1;
		if (a == 1)
		{
			long long value = c - data[b];
			data[b] = c;
			updateTree(data, tree, 0, n-1,1, b, value);
		}
		else
		{
			c -= 1;
			cout << returnSum(tree, 0, n-1,1, b,c) << endl;
		}
	}

}