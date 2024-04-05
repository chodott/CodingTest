#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Line
{
public:
	double dist = 0.f;
	int start;
	int end;
	Line(double d, int s, int e) : dist(d), start(s), end(e) {}
};

int findRoot(vector<int>& god_vec, int i)
{
	if (god_vec[i] == i) return i;
	else return god_vec[i] = findRoot(god_vec, god_vec[i]);
}

bool merge(vector<int>& god_vec, int a, int b)
{
	int a_root = findRoot(god_vec, a);
	int b_root = findRoot(god_vec, b);
	if (a_root == b_root) return false;
	
	if (a_root < b_root) god_vec[b_root] = a_root;
	else god_vec[a_root] = b_root;
	return true;
}

struct compare
{
	bool operator () (Line* l1, Line* l2) { return l1->dist > l2->dist; }
};

int main()
{
	int n, m;
	cin >> n >> m;
	double answer = 0;
	vector<pair<double, double>> pos_vec(1, { 0,0 });
	vector<int> god_vec(1, 0);
	priority_queue<Line*, vector<Line*>, compare> line_pq;
	for (int i = 1; i <= n; ++i)
	{
		double x, y;
		cin >> x >> y;
		god_vec.emplace_back(i);
		pos_vec.emplace_back(make_pair(x, y));
		for (int j = 1; j < i; ++j)
		{
			double dx = pos_vec[j].first; double dy = pos_vec[j].second;
			double dist = sqrt(pow((x - dx), 2) + pow((y - dy), 2));
			line_pq.push(new Line(dist, i, j));
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		bool bMerged = merge(god_vec, a, b);
	}

	while (!line_pq.empty())
	{
		Line* line = line_pq.top();
		line_pq.pop();
		if (!merge(god_vec, line->start, line->end)) continue;
		answer += line->dist;
	}

	cout.setf(std::ios_base::fixed);
	cout.precision(2);
	cout << answer;
}