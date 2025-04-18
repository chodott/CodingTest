#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> sumIndex_q;
    sumIndex_q.push({0,0});
    while(!sumIndex_q.empty())
    {
        int sum = sumIndex_q.front().first;
        int index = sumIndex_q.front().second;
        sumIndex_q.pop();
        if(index >= numbers.size())
        {
            if(sum == target) answer++;
            continue;
        }
        sumIndex_q.push({sum + numbers[index], index+1});
        sumIndex_q.push({sum - numbers[index], index+1});
        
    }
    return answer;
}