#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;

    int start = 1;
    int end = 100000;
    while (start < end)
    {
        long long solvingTime = 0;
        int level = (start + end) / 2;
        bool bSuccess = true;
        for (int i = 0; i < diffs.size(); ++i)
        {
            int time_cur = times[i];
            if (level >= diffs[i]) solvingTime += time_cur;
            else solvingTime += (diffs[i] - level) * (time_cur + times[i - 1]) + time_cur;
            if (solvingTime > limit)
            {
                bSuccess = false;
                break;
            }
        }
        if (bSuccess)
        {
            answer = min(answer, level);
            end = level;
        }
        else start = level + 1;
    }

    return answer;
}