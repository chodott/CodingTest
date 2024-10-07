#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	static Node* nodes[10000];
	static void addNode(int n, int child, int value)
	{
		if (nodes[n] == NULL) 
			nodes[n] = new Node(n);
		nodes[n]->child_vec.emplace_back(make_pair(child, value));
	}
	Node(int n) : num(n) {}
	vector<pair<int, int>> child_vec;
	int num = 0;
	pair<int, int> findFarNode(int parent, int sumValue)
	{
		pair<int, int> farNode{num, sumValue};
		for (auto& data : child_vec)
		{
			int n = data.first; int value = data.second;
			if (n == parent) continue;
			pair<int,int> d = nodes[n]->findFarNode(num, sumValue + value);
			if (farNode.second < d.second) farNode = d;
		}
		return farNode;
	}
};
Node* Node::nodes[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	Node::nodes[1] = new Node(1);
	while (n--> 1)
	{
		int root, child, value;
		cin >> root >> child >> value;
		Node::addNode(root, child, value);
		Node::addNode(child, root, value);
	}

	pair<int, int> rootData = Node::nodes[1]->findFarNode(1, 0);

	int root = rootData.first;
	cout << Node::nodes[root]->findFarNode(root, 0).second;

}