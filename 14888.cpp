#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int solve(vector<int>& num_vec, vector<int>& tool_vec)
{
	int answer = num_vec[0];
	for (int i=0;i<tool_vec.size();++i)
	{
		int target = num_vec[i + 1];
		switch (tool_vec[i])
		{
		case 0: answer += target; break;
		case 1: answer -= target; break;
		case 2: answer *= target; break;
		case 3: answer /= target; break;
		}
	}
	return answer;
}

int main()
{
	int n; cin >> n;
	vector<int> num_vec(n);
	vector<int> tool_vec;
	for(int i=0;i<n;++i) cin >> num_vec[i];
	for (int i = 0; i < 4; ++i)
	{
		int num; cin >> num;
		while (num--)
		{
			tool_vec.emplace_back(i);
		}
	}

	int maxAnswer = -INF; int minAnswer = INF;
	do
	{
		int value = solve(num_vec, tool_vec);
		maxAnswer = max(value, maxAnswer);
		minAnswer = min(value, minAnswer);
	} while (next_permutation(tool_vec.begin(), tool_vec.end()));
	cout << maxAnswer<<"\n"<<minAnswer;
}