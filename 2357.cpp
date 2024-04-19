#include <vector>
#include <stdio.h>
#define INF 1000000000
using namespace std;

pair<int,int> makeTree(int data[], vector<pair<int, int>>& tree,int start, int end, int index)
{
	if (start == end) return tree[index] = { data[start], data[start] };

	int mid = (start + end) / 2;
	pair<int, int> leftPair = makeTree(data, tree, start, mid, index * 2);
	pair<int, int> rightPair = makeTree(data, tree, mid + 1, end, index * 2 + 1);

	tree[index].first = min(leftPair.first, rightPair.first);
	tree[index].second = max(leftPair.second, rightPair.second);

	return tree[index];
}

pair<int, int> findPair(vector<pair<int, int>>& tree, int start, int end, int index, int startPos, int endPos)
{
	if (start > endPos || end < startPos) return { INF, 0 };
	
	if (start >= startPos && endPos >= end) return tree[index];
	int mid = (start + end) / 2;
	pair<int, int> leftPair = findPair(tree, start, mid, index * 2, startPos, endPos);
	pair<int, int> rightPair = findPair(tree, mid + 1, end, index*2+1, startPos, endPos);
	pair<int, int> pair;

	pair.first = min(leftPair.first, rightPair.first);
	pair.second = max(leftPair.second, rightPair.second);

	return pair;
}

int main()
{
	int n, m;
	int data[100000];
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> tree(n * 4, make_pair(0,0));
	for (int i = 0; i < n; ++i) scanf("%d", &data[i]);
	makeTree(data, tree, 0, n - 1, 1);
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		scanf("%d %d", &start, &end);
		start--; end--;
		pair<int, int> answer = findPair(tree, 0, n-1, 1, start, end);
		printf("%d %d\n", answer.first, answer.second);
	}
}