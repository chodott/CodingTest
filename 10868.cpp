#include <iostream>
#include <vector>
using namespace std;

#define INF 999999999

//구간합 구할 때처럼 세그먼트 트리를 써보자

int makeTree(vector<int>& min_tree, vector<int>& num_vec, int start, int end, int nodeNum)
{
	if (start == end)
		return min_tree[nodeNum] = num_vec[start];
	int mid = (end + start) / 2;

	return min_tree[nodeNum] = min(makeTree(min_tree, num_vec, start, mid, nodeNum * 2), 
													makeTree(min_tree, num_vec, mid + 1, end, nodeNum * 2 + 1));
}

int findMin(vector<int>& min_tree, int start, int end, int nodeNum, int range_start, int range_end)
{
	if (range_start <= start && range_end >= end) return min_tree[nodeNum];
	int mid = (end + start) / 2;

	int left = INF; int right = INF;

	if (range_start <= mid) left = findMin(min_tree, start, mid, nodeNum * 2, range_start, range_end);
	if (mid + 1 <= range_end) right = findMin(min_tree, mid + 1, end, nodeNum * 2 + 1, range_start, range_end);

	return(min(left, right));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<int> num_vec(n+1);
	vector<int> min_tree(n * 4);
	for(int i=1;i<=n;++i) cin >> num_vec[i];
	makeTree(min_tree, num_vec, 1, n, 1);
	while (m--)
	{
		int start, end; cin >> start >> end;
		cout<<findMin(min_tree, 1, n, 1, start, end)<<"\n";
	}

}