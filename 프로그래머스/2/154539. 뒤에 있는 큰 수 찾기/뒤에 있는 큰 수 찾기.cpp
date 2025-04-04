#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int length = numbers.size();
    vector<int> answer(length,-1);
    stack<int> num_stack;
    for(int i=length-1; i>=0; --i)
    {
        int num = numbers[i];    
        while(!num_stack.empty())
        {
            int value = num_stack.top();
            if(num < value)
            {
                answer[i] = value;
                break;
            }
            else num_stack.pop();
        }     
        num_stack.push(num);
    }
    return answer;
}