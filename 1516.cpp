#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Building
{
public:
	static vector<Building*> building_vec;
	static void addBuilding(Building* building) 
	{
		building_vec.emplace_back(building);
	}
	static void addSub(int i, int num)
	{
		building_vec[i-1]->sub_vec.emplace_back(building_vec[num-1]);
	}

	int returnMax()
	{
		if (bVisited) return value;
		int max = 0;
		for (auto& sub : sub_vec)
		{
			int time =  sub->returnMax();
			max = time < max ? max : time;
		}
		value += max;
		bVisited = true;
		return value;
	}

	Building() {};
	vector<Building*> sub_vec;
	int value;
	bool bVisited = false;

};

vector<Building*> Building::building_vec;

struct compare
{
	bool operator()(Building* b1, Building* b2)
	{
		return b1->sub_vec.size() > b2->sub_vec.size();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<Building*, vector<Building*>, compare> building_pq;
	for (int i = 0; i < n; ++i) Building::addBuilding(new Building());
	for(int i=1;i<=n;++i)
	{
		int num = 0; cin >> num;
		Building::building_vec[i - 1]->value = num;
		while (1)
		{
			cin >> num;
			if (num == -1) break;
			Building::addSub(i, num);
		}
	}

	for (auto& building : Building::building_vec) building_pq.push(building);
	while (!building_pq.empty())
	{
		auto* building = building_pq.top();
		building_pq.pop();
		if (building->bVisited) continue;
		building->returnMax();
	}
	for (auto& building : Building::building_vec) cout << building->value << "\n";
}