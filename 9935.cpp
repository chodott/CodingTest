#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main()
{
	string s, bomb;
	cin >> s >> bomb;
	stack<int> check_stack;
	deque<char> answer_dq;
	
	int curIndex = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		answer_dq.push_back(s[i]);
		//��ź ���ڿ��� �ϼ��Ǵ� ��
		if (bomb[curIndex] == s[i])
		{
			check_stack.push(curIndex++);

			//��ź �ϼ�.
			if (curIndex == bomb.length())
			{
				//���ÿ��� ��ź ����
				while (curIndex--)
				{
					check_stack.pop();
					answer_dq.pop_back();
				}
				//������ ���� ���� ��ź������� �Ǿ����� ��� �̾ üũ
				if (!check_stack.empty() && check_stack.top() != -1)
					curIndex = check_stack.top() + 1;
				//�ƴ� ��� �ʱ�ȭ
				else curIndex = 0;
			}
		}
		//���ο� ��ź�� ����
		else if (bomb[0] == s[i])
		{
			check_stack.push(0);
			curIndex = 1;
		}
		else
		{
			check_stack.push(-1);
			curIndex = 0;
		}
	}

	if (answer_dq.size() == 0) cout << "FRULA";
	else
	{
		for (char c : answer_dq) cout << c;
	}
}