#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
	int depth=0;
	int num;
	Node* parent;
	vector<Node*> children;

	Node(int n): num(n) {};
	Node(int n, Node* pn):num(n)
	{ 
		addParent(pn);
		updateDepth();
	}
	void addChild(Node* cn) { children.emplace_back(cn); }
	void updateDepth()
	{
		depth = parent->depth + 1;
		for (auto* child : children)
		{
			child->updateDepth();
		}
	}
	void addParent(Node* pn)
	{
		parent = pn;
		pn->addChild(this);
	}
};

int returnParent(map<int, Node*> node_map, int a, int b)
{
	Node* node_a = node_map[a];
	Node* node_b = node_map[b];

	while (node_a->num != node_b->num)
	{
		if (node_a->depth < node_b->depth) node_b = node_b->parent;
		else node_a = node_a->parent;
	}
	return node_a->num;
}

int main()
{
	int t;
	int data[10000];
	cin >> t;
	while (t > 0)
	{
		t -= 1;
		fill(&data[0], &data[10000], 0);
		
		map<int, Node*> node_map;
		int n;
		int a, b;
		cin >> n;
		for (int i = 1; i < n; ++i)
		{
			cin >> a >> b;
			if (node_map[a] == nullptr) node_map[a] = new Node(a);
			if (node_map[b] == nullptr) node_map[b] = new Node(b, node_map[a]);
			else node_map[b]->addParent(node_map[a]);
		}
		cin >> a >> b;
		cout << returnParent(node_map, a, b) << endl;
	}
}