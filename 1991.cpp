#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	char c;
	Node* left = NULL;
	Node* right = NULL;
	Node(char type) : c(type) {}

	void preorder()
	{
		cout << c;
		if (left != NULL) left->preorder();
		if (right != NULL) right->preorder();
	}

	void inorder()
	{
		if (left != NULL) left->inorder();
		cout << c;
		if (right != NULL) right->inorder();
	}

	void postorder()
	{
		if (left != NULL) left->postorder();
		if (right != NULL) right->postorder();
		cout << c;

	}
};

int main()
{
	int n; cin >> n;
	vector<Node*> node_vec;
	for (int i = 0; i < n; ++i) node_vec.emplace_back(new Node(i + 65));
	while (n--)
	{
		char root, left, right;
		cin >> root>>left>>right;
		if (left != '.') node_vec[root-65]->left = node_vec[left-65];
		if (right != '.') node_vec[root-65]->right = node_vec[right-65];
	}

	node_vec[0]->preorder(); cout << "\n";
	node_vec[0]->inorder();	cout << "\n";
	node_vec[0]->postorder();
}