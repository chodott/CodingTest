#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
BFS
1. PQ에 pair<count, value>를 count가 작은 순으로 관리
2. 하나씩 POP하면서 연산 적용
3. VALUE == 목표 일때 return / else일 떄 다시 PQ에 삽입
--> 시간초과;

y -> x로 변환해보자
2나 3으로 나누어떨어지지 않으면 의미없는 경우의 수
*/

int solution(int x, int y, int n) {
    int answer = -1;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> result_pq;
    result_pq.push(make_pair(0,y));
    while(!result_pq.empty())
    {
        const pair<int,int>& data = result_pq.top();
        int value = data.second;
        int count = data.first;
        result_pq.pop();
        if(value <x) continue;
        else if(value == x) return count;
        count++;
        result_pq.push(make_pair(count, value - n));
        if(value%2 ==0) result_pq.push(make_pair(count, value / 2));
        if(value%3 ==0) result_pq.push(make_pair(count, value / 3));
    }
    return answer;
}