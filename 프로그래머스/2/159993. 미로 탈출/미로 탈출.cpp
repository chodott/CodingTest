#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

/*
bfs
start -> lever
lever -> goal
*/
int bfs(vector<string>& maps, pair<int,int>& pos, char target)
{
    vector<vector<bool>> visited_vec(maps.size(), vector<bool>(maps[0].size(), false));
    queue<tuple<int,int,int>> pos_q;
    pos_q.push(make_tuple(pos.first, pos.second, 0));
    while(!pos_q.empty())
    {
        tuple<int,int, int> cur = pos_q.front();
        pos_q.pop();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int value = get<2>(cur);
        
        if(y < 0 || x < 0 || y >= maps.size() || x >=maps[0].size()) continue;
        if(visited_vec[y][x] == true) continue;
        if(maps[y][x] == 'X') continue;
        
        if(maps[y][x] == target) return value;   
        visited_vec[y][x] = true;
        pos_q.push(make_tuple(y+1, x, value+1));
        pos_q.push(make_tuple(y, x+1, value+1));
        pos_q.push(make_tuple(y, x-1, value+1));
        pos_q.push(make_tuple(y-1, x, value+1));
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int,int> startPos;
    pair<int,int> leverPos;
    for(int i=0;i<maps.size();++i)
    {
        for(int j=0;j<maps[i].size();++j)
        {
            if(maps[i][j] == 'S') startPos = {i,j};
            else if(maps[i][j] == 'L') leverPos = {i,j};
        }
    }
    
    int cnt2Lever = bfs(maps, startPos, 'L');
    int cnt2Exit = bfs(maps, leverPos, 'E');
    if(cnt2Lever ==-1 || cnt2Exit == -1) return -1;
    answer = cnt2Lever + cnt2Exit;
    return answer;
}