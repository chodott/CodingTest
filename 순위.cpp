#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

//승 + 패 == 인원수 - 1 -> 순위 결정 가능

using namespace std;

class Player
{
public:
    static vector<Player*> players_vec;
    vector<int> win_vec;
    vector<int> lose_vec;
    void calculateLose(set<int>& lose_set)
    {
        for (int i : lose_vec)
        {
            if (lose_set.count(i) != 0) continue;
            lose_set.insert(i);
            players_vec[i]->calculateLose(lose_set);
        }
    }

    void calculateWin(set<int>& win_set)
    {
        for (int i : win_vec)
        {
            if (win_set.count(i) != 0) continue;
            win_set.insert(i);
            players_vec[i]->calculateWin(win_set);
        }
    }
};

vector<Player*> Player::players_vec;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i <= n; ++i) Player::players_vec.emplace_back(new Player());
    for (auto& result : results)
    {
        Player* winner = Player::players_vec[result[0]];
        Player* loser = Player::players_vec[result[1]];
        winner->win_vec.emplace_back(result[1]);
        loser->lose_vec.emplace_back(result[0]);
    }

    for (auto* player : Player::players_vec)
    {
        set<int> win_set; set<int> lose_set;
        player->calculateWin(win_set); player->calculateLose(lose_set);
        if (n - 1 == win_set.size() + lose_set.size())
            answer++;
        cout << win_set.size() << ", " << lose_set.size() << endl;
    }
    return answer;
}