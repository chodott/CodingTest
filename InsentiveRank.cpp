#include <string>
#include <vector>
#include <map>

using namespace std;

bool canInsentive(int i, map<int, vector<int>, greater<int>>& score_map, vector<vector<int>> scores)
{
    vector<int> score = scores[i];
    for (auto& info : score_map)
    {
        if (info.first - 2 < score[0] + score[1]) break;
        for (int index : info.second)
        {
            if (scores[index][0] > score[0] && scores[index][1] > score[1])
                return false;
        }
    }
    return true;
};

int solution(vector<vector<int>> scores) {
    int answer = 1;
    map<int, vector<int>, greater<int>> score_map;
    int wanho_score = scores[0][0] + scores[0][1];
    for (int i = 0; i < scores.size(); ++i)
    {
        vector<int>& score = scores[i];
        score_map[score[0] + score[1]].emplace_back(i);
    }

    for (auto& score : score_map)
    {
        if (wanho_score >= score.first) break;
        answer += score.second.size();
        for (int i : score.second)
        {
            if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
            if (!canInsentive(i, score_map, scores)) answer--;
        }
    }
    return answer;
}