#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
	vector<pair<int, int>> connected_datas;
	bool bChecked = false;
	int num;
	Node(int n) : num(n) {}

	inline void addData(pair<int, int> data) { connected_datas.emplace_back(data); }
	int returnRadius(vector<Node*>& node_vec)
	{
		bChecked = true;
		int maxDist = 0;
		for (auto& cd : connected_datas)
		{
			if (node_vec[cd.first]->bChecked) continue;
			maxDist = max(maxDist, cd.second + node_vec[cd.first]->returnRadius(node_vec));
		}
		return maxDist;
	}
};

int main()
{
	int v; cin >> v;
	vector<Node*> node_vec(v + 1);
	vector<int> leafNum_vec;
	int rootNum = 0;
	while (v--)
	{
		int num, a, b; cin >> num;
		node_vec[num] = new Node(num);
		while (1)
		{
			cin >> a;
			if (a == -1) break;
			cin >> b;
			node_vec[num]->addData(make_pair(a, b));
		}
		if (node_vec[num]->connected_datas.size() == 1)
			leafNum_vec.emplace_back(num);
	}

	int answer = 0;
	for (int leaf : leafNum_vec)
	{
		int value = node_vec[leaf]->returnRadius(node_vec);
		answer = max(answer, value);
		for (int i = 1; i < node_vec.size(); ++i) node_vec[i]->bChecked = false;
	}
	cout << answer;
}