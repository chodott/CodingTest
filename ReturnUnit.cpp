#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    map<int, vector<int>> dest_map;
    queue<int> dest_q;
    pair<int, bool> data[n];
    pair<int, bool> defaultPair = { -1, false };
    fill(&data[0], &data[n], defaultPair);  //{-100, false} = 이런 식으로 바로 객체 생성해서 넣으면 에러!
    int cnt = 1; int nextCnt = 0;
    int length = 0;
    for (auto& road : roads)
    {
        dest_map[road[0]].emplace_back(road[1]);
        dest_map[road[1]].emplace_back(road[0]);
    }
    dest_q.push(destination);
    while (!dest_q.empty())
    {   //bfs 
        int pos = dest_q.front();
        dest_q.pop();
        if (data[pos - 1].second != true)
        {
            data[pos - 1] = { length, true };
            for (int next : dest_map[pos]) dest_q.push(next);
            nextCnt += dest_map[pos].size();
        }
        if (--cnt == 0)
        {
            length++;
            cnt = nextCnt;
            nextCnt = 0;
        }
    }

    for (int source : sources) answer.emplace_back(data[source - 1].first);
    return answer;
}