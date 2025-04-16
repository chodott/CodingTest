#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int count = 0;
    deque<char> de{s.begin(), s.end()};
    while(count++ < s.length())
    {
        stack<char> st;
        bool bFailed = false;
        for(char c : de)
        {
            switch(c)
            {
                case '{': case '(': case '[': st.push(c); break;
                case '}':
                    if(st.empty() ||st.top() != '{') bFailed = true;
                    else st.pop();
                    break;
                case ')':
                    if(st.empty() || st.top() != '(') bFailed = true;
                    else st.pop();
                    break;
                case ']':
                    if(st.empty() ||st.top() != '[') bFailed = true;
                    else st.pop();
                    break;
            }
            if(bFailed) break;
        }
        if(!bFailed && st.empty()) answer++;        
        de.emplace_back(de.front());
        de.pop_front();
    }
    return answer;
}