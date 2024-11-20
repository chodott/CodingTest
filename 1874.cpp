#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> input;
	for (int i = 1; i <= n; ++i)
		input.emplace_back(i);

	stack<int> stack;
	vector<char> char_vec;
	int index = 0;
	while (n--)
	{
		int target; cin >> target;
		while (index<input.size())
		{
			if (stack.empty() || stack.top() != target)
			{
				stack.push(input[index++]);
				char_vec.emplace_back('+');
			}
			
			if(stack.top() == target) break;
		}

		if (stack.top() == target)
		{
			char_vec.emplace_back('-' );
			stack.pop();
		}
		else
		{
			cout << "NO"; return 0;
		}
	}
	for (char c : char_vec) cout << c << "\n";
}



/*
�ش� ������ ������ ����Ͽ� Ǯ����.

����

1. ������ �� ������ n�� �Է¹޴´�.
2. ������ top�� n�� �� �� ���� 1���� n���� ���Ҹ� ����ִ´�.
3. �̶� �Էµ� ������ ���� �� ���� �� ����� ���� ��ȣ�� ���Ϳ� �����Ѵ�. +
4. ���ÿ� ���Ҹ� ���� �� +, ���� -�� char_vec�� �����Ѵ�.
5. 1~n���� ���Ҹ� ��� stack�� �־��µ��� ������ top�� 
n�� �ƴ� ��� �־��� ������ �ϼ��� �� �����Ƿ� NO ��� �� ����
6. �־��� N�� ��� ���ÿ��� �����µ� ������ ��� ������ char_vec��
���ʷ� ����Ͽ� ���� ����.
*/