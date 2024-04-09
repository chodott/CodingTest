#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Line
{
public:
	int start;
	int end;
	int length;
	Line(int s, int e, int l) : start(s), end(e), length(l) {}
};

struct compare
{
	bool operator () (Line* l1, Line* l2) { return l1->length > l2->length; }
};

void makeIsland(vector<vector<int>>& board, int i, int j, int n, int m, int num)
{
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (board[i][j] != 1) return;
	board[i][j] = num;
	makeIsland(board, i+1, j, n, m, num);
	makeIsland(board, i-1, j, n, m, num);
	makeIsland(board, i, j+1, n, m, num);
	makeIsland(board, i, j-1, n, m, num);
}

int findRoot(vector<int>& root_vec, int i)
{
	if (root_vec[i]-2 == i) return i;
	else return root_vec[i] = findRoot(root_vec, root_vec[i]);
}

bool merge(vector<int>& root_vec, int a, int b)
{
	int root_a = findRoot(root_vec, a);
	int root_b = findRoot(root_vec, b);
	if (root_a == root_b) return false;
	
	if (root_a < root_b) root_vec[root_b] = root_a;
	else root_vec[root_a] = root_b;
	return true;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	priority_queue<Line*, vector<Line*>, compare> line_pq;
	int num = 2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <  m; ++j)
		{
			cin >> board[i][j];
		}
	}
	vector<pair<int, int>> save(m, { 0,0 });
	for (int i = 0; i < n; ++i)
	{
		pair<int,int> cur; 
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0) continue;
			else if(board[i][j] == 1) makeIsland(board, i, j, n, m, num++);
			
			if(j-cur.first > 2 && cur.second != 0) 
				line_pq.push(new Line(cur.second, board[i][j], j - cur.first-1));
			cur = { j, board[i][j] };

			if (i - save[j].first > 2 && save[j].second != 0)
				line_pq.push(new Line(save[j].second, board[i][j], i - save[j].first - 1));
			save[j] = { i, board[i][j] };
		}
	}

	vector<int> root_vec;
	for (int i = 2; i < num; ++i){root_vec.emplace_back(i);}
	int cnt = 1;
	int length = 0;
	while (!line_pq.empty())
	{
		Line* line = line_pq.top();
		line_pq.pop();

		if (!merge(root_vec, line->start-2, line->end-2)) continue;
		//cout << line->start << ", " << line->end << " :" << line->length << endl;
		cnt++;
		length += line->length;
		if (cnt == root_vec.size()) break;
	}

	if (cnt != root_vec.size()) cout << -1;
	else cout << length;
}