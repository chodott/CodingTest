#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Line
{
public:
	int start;
	int end;
	int dist;
	Line(int s, int e, int d) : start(s), end(e), dist(d) {}
};

struct compare
{
	bool operator () (Line* l1, Line* l2) { return l1->dist > l2->dist; }
};

int findRoot(vector<int>& index_vec, int i)
{
	if (index_vec[i] == i) return i;
	else return index_vec[i] = findRoot(index_vec, index_vec[i]);
}

bool merge(vector<int>& index_vec, int a, int b)
{
	int a_root = findRoot(index_vec, a);
	int b_root = findRoot(index_vec, b);
	if (a_root == b_root) return false;
	
	if (a_root < b_root) index_vec[b_root] = a_root;
	else index_vec[a_root] = b_root;
	return true;
}

int main()
{
	while (1)
	{
		int m, n;
		int answer = 0;
		int cnt = 0;
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		priority_queue<Line*, vector<Line*>, compare> line_pq;
		vector<int> index_vec;

		for (int i = 0; i < n; ++i)
		{
			int x; int y; int z;
			cin >> x >> y >> z;
			line_pq.push(new Line(x, y, z));
			index_vec.emplace_back(i);
			answer += z;
		}

		while (!line_pq.empty())
		{
			Line* line = line_pq.top();
			line_pq.pop();
			if (!merge(index_vec, line->start, line->end)) continue;
			cnt++;
			if (cnt == m) break;
			answer -= line->dist;
		}
		cout << answer << endl;
	}
}
