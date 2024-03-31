#include <iostream>
#include <vector>
using namespace std;

void result(vector<vector<int>>& mat, long long b, int n)
{
	if (b == 1) return;

	vector<vector<int>> newMat(n, vector<int>(n, 0));
	vector<vector<int>> base = mat;

	result(mat, b/2, n);
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
				newMat[i][j] += mat[i][k] * mat[k][j];

			newMat[i][j] %= 1000;
		}
	}
	mat = newMat;

	vector<vector<int>> newnewMat(n, vector<int>(n, 0));
	if (b % 2 != 1) return;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
				newnewMat[i][j] += newMat[i][k] * base[k][j];

			newnewMat[i][j] %= 1000;
		}
	}
	mat = newnewMat;
}

int main()
{
	int n;
	long long b;
	cin >> n >> b;
	vector<vector<int>> mat(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}
	result(mat, b,n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<< mat[i][j] % 1000 << " ";
		}
		cout << endl;
	}
}