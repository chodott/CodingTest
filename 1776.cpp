#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Problem
{
public:
	int num;
	int value = 0;
	vector<Problem*> next_vec;
	Problem(int n) : num(n) {}
	void addNext(Problem* next) { next_vec.emplace_back(next);}
};

bool compare(Problem* p1, Problem* p2)
{
	if (p1->value == p2->value)
		return p1->num < p2->num;
	return p1->value < p2->value;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Problem*> prob_vec;
	priority_queue<int, vector<int>, greater<int>> next_q;
	for (int i = 0; i < n; ++i) prob_vec.emplace_back(new Problem(i));

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		prob_vec[--a]->addNext(prob_vec[--b]);
		prob_vec[b]->value += 1;
	}
	
	for (auto& prob : prob_vec)
	{
		if (prob->value != 0) continue;
		next_q.push(prob->num);
	}

	while (!next_q.empty())
	{
		Problem* cur = prob_vec[next_q.top()];
		next_q.pop();
		for (auto& prob : cur->next_vec)
		{
			prob->value -= 1;
			if (prob->value == 0) next_q.push(prob->num);
		}
		cout << cur->num+1 <<" ";
	}

}