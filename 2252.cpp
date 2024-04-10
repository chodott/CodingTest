#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Student
{
public:
	int num;
	bool visited = false;
	vector<Student*> tall_vec;
	Student(int n) :num(n) {}
	void addTall(Student* stu) { tall_vec.emplace_back(stu); }
	void addList(stack<int>& answer_stack)
	{
		if (visited) return;
		visited = true;
		for (auto& stu : tall_vec)
		{
			stu->addList(answer_stack);
		}
		answer_stack.push(num);
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Student*> student_vec;
	stack<int> answer_stack;
	for (int i = 0; i < n; ++i) student_vec.emplace_back(new Student(i));

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		student_vec[--a]->addTall(student_vec[--b]);
	}

	for (int i = 0; i < n; ++i)
		student_vec[i]->addList(answer_stack);

	while (!answer_stack.empty())
	{
		int num = answer_stack.top() + 1;
		answer_stack.pop();
		cout << num << " ";
	}
}