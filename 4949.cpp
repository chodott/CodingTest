#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
	while (1)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		stack<char>left_stack;
		string input;
		bool result = true;
		getline(cin, input);
		if (input == ".") break;

		for (char c : input)
		{
			if(c == '(' || c=='[') left_stack.push(c);
			else if (c == ')')
			{
				if (!left_stack.empty() && left_stack.top() == '(')
					left_stack.pop();
				else
				{
					result = false;
					break;
				}
			}
			else if (c == ']')
			{
				if (!left_stack.empty() && left_stack.top() == '[')
					left_stack.pop();
				else
				{
					result = false;
					break;
				}
			}
		}

		if (left_stack.size() != 0 || !result ) cout << "no" << endl;
		else cout << "yes" << endl;
	}

}