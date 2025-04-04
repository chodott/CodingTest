#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int length = numbers.size();
    vector<int> answer;
    stack<int> num_stack;
    for(int i=length-1; i>=0; --i)
    {
        int num = numbers[i];    
        bool bSuccess = false;
        while(!num_stack.empty())
        {
            int value = num_stack.top();
            if(num < value)
            {
                answer.push_back(value);
                bSuccess = true;
                break;
            }
            else num_stack.pop();
        }     
        num_stack.push(num);
        if(!bSuccess) answer.push_back(-1);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}