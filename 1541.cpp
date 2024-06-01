#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string equation;
	cin >> equation;
	int start = 0; int answer = 0;
	int count = 0; 
	bool bFrontMinus = false;
	for (int i=0; i<equation.size(); ++i)
	{
		char c = equation[i];
		int num = 0;
		switch (c)
		{
		case '-': case '+':
			num = stoi(equation.substr(start, count), 0);
			if (!bFrontMinus) answer += num;
			else answer -= num;
			start = i + 1;
			count = 0;
			if(c=='-') 	bFrontMinus = true;
			break;

		default:
			count++;
		}

		if (i == equation.size() - 1)
		{
			num = stoi(equation.substr(start, count), 0);
			if (!bFrontMinus) answer += num;
			else answer -= num;
		}
	}
	cout << answer;
}