#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool solve(string answer)
{
	int result = 0;
	int num = 0;
	int cnt = 0;
	for (int i = answer.length() - 1; i >= 0; --i)
	{
		if (answer[i] == '+')
		{
			result += num;
			cnt = 0;
			num = 0;
		}
		else if (answer[i] == '-')
		{
			result -= num;
			cnt = 0;
			num = 0;
		}
		else if (answer[i] ==  ' ') cnt++;
		else num += stoi(answer.substr(i, 1)) * pow(10, cnt);
	}
	result += num;		//첫번째 수
	if (result == 0) return true;
	return false;
}

void dfs(vector<string>& answer_vec, string answer, int cur, int max)
{
	answer += to_string(cur);
	if (cur == max)
	{
		if (solve(answer) == true) answer_vec.emplace_back(answer);
		return;
	}
	dfs(answer_vec, answer+ "+", cur + 1, max);
	dfs(answer_vec, answer +  "-", cur + 1, max);
	dfs(answer_vec, answer + " ", cur + 1, max);
}

bool compare(string& s1, string& s2) {return s1 < s2;};

int main()
{
	int n;
	cin >> n;
	vector<vector<string>> answer_vec(n, vector<string>());
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		dfs(answer_vec[i], "1+", 2, num);
		dfs(answer_vec[i], "1-", 2, num);
		dfs(answer_vec[i], "1 ", 2, num);
		sort(answer_vec[i].begin(), answer_vec[i].end(), compare);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < answer_vec[i].size(); ++j)
			cout << answer_vec[i][j] << endl;
		cout << endl;
	}
}