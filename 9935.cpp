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
		//ÆøÅº ¹®ÀÚ¿­ÀÌ ¿Ï¼ºµÇ´Â Áß
		if (bomb[curIndex] == s[i])
		{
			check_stack.push(curIndex++);

			//ÆøÅº ¿Ï¼º.
			if (curIndex == bomb.length())
			{
				//½ºÅÃ¿¡¼­ ÆøÅº Á¦°Å
				while (curIndex--)
				{
					check_stack.pop();
					answer_dq.pop_back();
				}
				//½ºÅÃÀÇ ´ÙÀ½ °ªÀÌ ÆøÅººôµå¾÷ÀÌ µÇ¾îÀÖÀ» °æ¿ì ÀÌ¾î¼­ Ã¼Å©
				if (!check_stack.empty() && check_stack.top() != -1)
					curIndex = check_stack.top() + 1;
				//¾Æ´Ò °æ¿ì ÃÊ±âÈ­
				else curIndex = 0;
			}
		}
		//»õ·Î¿î ÆøÅºÀÇ ½ÃÀÛ
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