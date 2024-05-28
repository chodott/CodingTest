#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Line
{
public:
	int start;
	int end;
	int value;
	Line(int s, int e, int v) : start(s), end(e), value(v) {}

};

struct compare
{
	bool operator () (Line* l1, Line* l2)
	{
		return l1->value > l2->value;
	}
};

int getRoot(vector<int>& root_vec, int num)
{
	if (num == root_vec[num]) return num;
	else return root_vec[num] = getRoot(root_vec, root_vec[num]);
}

bool merge(vector<int>& root_vec, int a, int b)
{
	int root_a = getRoot(root_vec, a);
	int root_b = getRoot(root_vec, b);

	if (root_a == root_b) return false;

	if (root_a < root_b) root_vec[root_b] = root_a;
	else root_vec[root_a] = root_b;
	return true;
}

int main()
{
	int v, e;
	double answer = 0;
	cin >> v >> e;
	priority_queue<Line*, vector<Line*>, compare> line_pq;
	vector<int> root_vec;
	for (int i = 0; i <= v; ++i) {root_vec.emplace_back(i); }

	while (e--)
	{
		int a, b, value;
		cin >> a >> b >> value;
		line_pq.push(new Line(a, b, value));
	}

	while (!line_pq.empty())
	{
		Line* line = line_pq.top();
		line_pq.pop();

		if (merge(root_vec, line->start, line->end) == false) continue;

		answer += line->value;

	}
	cout << answer;
}