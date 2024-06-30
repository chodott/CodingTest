#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printPreorder(vector<int>& inorder, vector<int>& postorder, vector<int>& index, int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd) return;

	int rootNum = postorder[postEnd];
	int inMidIdx = index[rootNum];
	int leftLength = inMidIdx - inStart;
	int rightLength = inEnd - inMidIdx;
	
	cout << rootNum <<' ';

	printPreorder(inorder, postorder, index, inStart, inMidIdx - 1, postStart, postStart + leftLength - 1);
	printPreorder(inorder, postorder, index, inMidIdx + 1, inEnd, postStart + leftLength, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	vector<int> inorder_vec(n);
	vector<int> postorder_vec(n);
	vector<int> index_vec(n + 1);
	queue<int> root_q;
	for (int i = 0; i < n; ++i) 
	{
		cin >> inorder_vec[i];
		index_vec[inorder_vec[i]] = i;
	}
	for (int i = 0; i < n; ++i) cin >> postorder_vec[i];

	printPreorder(inorder_vec, postorder_vec, index_vec, 0, n-1, 0, n-1);
}