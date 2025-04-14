#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> gwalho_stack;
    for(char c : s)
    {
        if(c == '(') gwalho_stack.push(c);
        else
        {
            if(gwalho_stack.empty()) return false;
            else gwalho_stack.pop();
        }
    }
    if(gwalho_stack.empty()) return true;
    else return false;
}