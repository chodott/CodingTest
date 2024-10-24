#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	bool arr[100][100];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[i][j] = arr[i][k] && arr[k][j] ? 1 : arr[i][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i][j] <<" ";
		}
		cout << "\n";
	}
}