#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

void makeOil(vector<vector<int>>& land, int i, int j, int n, int m, int num, int& cnt)
{

    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (land[i][j] != 1) return;

    land[i][j] = num;
    cnt += 1;
    makeOil(land, i + 1, j, n, m, num, cnt);
    makeOil(land, i, j + 1, n, m, num, cnt);
    makeOil(land, i - 1, j - 1, n, m, num, cnt);
    makeOil(land, i, j - 1, n, m, num, cnt);

}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    vector<int> oil_vec(2, 0);
    int n = land.size();
    int m = land[0].size();
    int num = 2;
    for (int i = 0; i < land.size(); ++i)
    {
        for (int j = 0; j < land[0].size(); ++j)
        {
            if (land[i][j] != 1) continue;
            int cnt = 0;
            makeOil(land, i, j, n, m, num++, cnt);
            oil_vec.emplace_back(cnt);
        }
    }

    for (int j = 0; j < m; ++j)
    {
        int sum = 0;
        set<int> num_set;
        for (int i = 0; i < n; ++i)
        {
            if (land[i][j] <= 1) continue;
            num_set.insert(land[i][j]);
        }

        for (int num : num_set)
            sum += oil_vec[num];

        answer = answer < sum ? sum : answer;
    }

    return answer;
}