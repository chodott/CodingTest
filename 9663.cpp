#include <iostream>
#include <vector>

using namespace std;

void findCase(vector<int> queenPos_vec, int n, int column, int& answer)
{
	if (column ==n)
	{
		answer++;
		return;
	}

	for (int i = 0; i < queenPos_vec.size(); ++i)
	{
		bool enable = true;
		for (int j = 0; j < column; ++j)
		{
			if (queenPos_vec[j] == i) enable = false;
			if (abs(queenPos_vec[j] - i) == abs(column - j)) enable = false;

			if (!enable) break;
		}

		if (!enable) continue;
			
		queenPos_vec[column] = i;
		findCase(queenPos_vec, n, column+1, answer);
		
	}
}

int main()
{
	int n;
	int answer = 0;
	cin >> n;
	vector<int> queenPos_vec(n, -1);

	findCase(queenPos_vec, n, 0, answer);
	cout << answer << endl;
}