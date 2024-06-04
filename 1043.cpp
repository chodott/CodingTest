#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	int count; cin >> count;
	map<int, vector<int>> NumParty_map;
	vector<vector<int>>		partyMember_vec;
	queue<int> fool_q;
	vector<bool> fact_vec; //0: ó��, 1: ����
	set<int> foolparty_set;
	for (int i = 0; i < m; ++i) foolparty_set.insert(i);
	for (int i = 0; i < n + 1; ++i) fact_vec.emplace_back(0);
	while (count--)
	{	//������ �ƴ� �ο� �ʱ�ȭ
		int num; cin >> num;
		fact_vec[num] = 1;
		fool_q.push(num);
	}
	
	for(int party=0; party < m;++party)
	{//��Ƽ �ʱ�ȭ
		cin >> count;
		vector<int> num_vec(count, 0);
		for (int i = 0; i < count; ++i)
		{
			int num; cin >> num;
			num_vec[i] = num;
			NumParty_map[num].emplace_back(party);
		}
		partyMember_vec.emplace_back(num_vec);
	}

	while(!fool_q.empty())
	{
		int num = fool_q.front();
		fool_q.pop();
		for (int party : NumParty_map[num])
		{
			for (int member : partyMember_vec[party])
			{
				if (fact_vec[member] == true) continue;
				fact_vec[member] = true;
				fool_q.push(member);
			}
			foolparty_set.erase(party);
		}
	}
	cout << foolparty_set.size();

}