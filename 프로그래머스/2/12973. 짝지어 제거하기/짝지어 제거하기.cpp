#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> char_st;
    for(char c : s)
    {
        if(char_st.empty()) char_st.push(c);
        else
        {
            if(char_st.top() == c) char_st.pop();
            else char_st.push(c);
        }
    }
    answer = char_st.empty()?1:0;
    return answer;
}