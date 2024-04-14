#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Team
{
public:
	int num;
	int cnt = 0;
	Team(int n) :num(n) {}
};

bool compare(Team* t1, Team* t2)
{
	return t1->cnt > t2->cnt;
}
int main()
{
	int testCnt;
	cin >> testCnt;
	while (testCnt > 0)
	{
		map<int, int> index_map;
		vector<Team*> team_vec;
		testCnt -= 1;
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			team_vec.emplace_back(new Team(a));
			index_map[a] = i;
			for (auto& team : team_vec) team->cnt++;
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			int a_num = index_map[a];
			int b_num = index_map[b];
			Team* a_team = team_vec[a_num];
			Team* b_team = team_vec[b_num];
			if (a_num < b_num)
			{
				a_team->cnt -= 1;
				b_team->cnt += 1;
			}
			else
			{
				a_team->cnt += 1;
				b_team->cnt -= 1;
			}
		}
		
		sort(team_vec.begin(), team_vec.end(), compare);

		vector<int> rank_vec;
		int save = -1;
		bool bStable = true;
		for (auto& team : team_vec)
		{
			if (save == team->cnt)
			{
				bStable = false;
				break;
			}
			save = team->cnt;
			rank_vec.emplace_back(team->num);
		}
		if (bStable)
		{
			for (int r : rank_vec) cout << r << " ";
		}
		else cout << "IMPOSSIBLE";

		cout << "\n";
	}
}