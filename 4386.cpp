#include<iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Line
{
public:
	int start = 0;
	int end = 0;
	float dist = 0;
	Line(int s, int e, float d) : start(s), end(e), dist(d) {};
};

struct compare
{
	bool operator ()(Line* l1, Line* l2)
	{
		return l1->dist > l2->dist;
	}
};

int findRoot(vector<int>& index_vec, int n)
{
	if (n == index_vec[n]) return n;
	else return index_vec[n] = findRoot(index_vec, index_vec[n]);
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
	int n;
	cin >> n;
	float answer = 0;
	int cnt = 1;
	vector<pair<float, float>> star_vec(n, { 0,0 });
	priority_queue<Line*, vector<Line*>, compare> pq;
	vector<int> index_vec;

	for (int i = 0; i < n; ++i)
	{
		index_vec.emplace_back(i);
		float x, y;
		cin >> x >> y;
		star_vec[i] = { x,y };
		for (int j = 0; j < i; ++j)
		{
			float dx = star_vec[j].first; float dy = star_vec[j].second;
			float dist = sqrt(pow(x - dx, 2) + pow(y - dy, 2));
			pq.push(new Line(i, j, dist));
		}
	}

	while (cnt < n)
	{
		Line* line = pq.top();
		pq.pop();
		
		if (!merge(index_vec, line->start, line->end)) continue;
		cnt++;
		answer += line->dist;
	}
	cout << answer << endl;
}