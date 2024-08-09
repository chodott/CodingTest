#include <iostream>
#include <vector>
using namespace std;

bool bCanMove(int value, pair<int, int>& data, int length)
{
	if (abs(value - data.first) > 1) return false;

	if (value == data.first) data.second += 1;
	else if (value < data.first)
	{
		if (data.second < 0) return false;
		else data = { value, -length + 1 };
	}
	else
	{
		if (data.second < length) return false;
		else data = { value, 1};
	}
	return true;
}

int main()
{
	int n, l, answer = 0;
	cin >> n >> l;
	vector<vector<int>> map_vec(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map_vec[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		pair<int, int> row_data, column_data; //<height, blank>
		bool bSuccess_row = true; bool  bSuccess_column = true;
		row_data = { map_vec[i][0], 1}; column_data = { map_vec[0][i], 1};
		for (int j = 1; j < n; ++j)
		{
			bSuccess_row = 
				bSuccess_row == true ? bCanMove(map_vec[i][j], row_data, l) : false;

			bSuccess_column =
				bSuccess_column == true ? bCanMove(map_vec[j][i], column_data, l) : false;
		}
		if (bSuccess_row == true && row_data.second >= 0) answer += 1;
		if (bSuccess_column == true && column_data.second >=0 ) answer += 1;
	}
	cout << answer;
}
