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
해당 문제는 스택을 사용하여 풀었다.

로직

1. 수열의 각 원소인 n을 입력받는다.
2. 스택의 top이 n이 될 때 까지 1부터 n까지 원소를 집어넣는다.
3. 이때 입력된 수열을 만들 수 있을 때 출력할 연산 기호를 벡터에 저장한다. +
4. 스택에 원소를 넣을 때 +, 뺄때 -를 char_vec에 저장한다.
5. 1~n까지 원소를 모두 stack에 넣었는데도 스택의 top이 
n이 아닐 경우 주어진 수열을 완성할 수 없으므로 NO 출력 후 종료
6. 주어진 N을 모두 스택에서 빼내는데 성공한 경우 저장한 char_vec를
차례로 출력하여 정답 도출.
*/