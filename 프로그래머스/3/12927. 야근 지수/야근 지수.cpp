#include <string>
#include <vector>
#include <queue>
using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>> work_pq;
    for(int work: works)work_pq.push(work);
    while(n--)
    {
        int value = work_pq.top() - 1;
        work_pq.pop();
        work_pq.push(value);
    }
    while(!work_pq.empty())
    {
        int value = work_pq.top();
        if(value>=0) answer += value * value;
        work_pq.pop();
    }
    return answer;
}