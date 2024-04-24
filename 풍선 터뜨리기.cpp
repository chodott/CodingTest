#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool bLastBalloon(vector<int>& vec, pair<int, int> data[], int index)
{
    int cur = vec[index];

    if (data[index].first < cur && data[index].second < cur) return false;
    else return true;
}

int solution(vector<int> a) {
    int answer = 0;
    pair<int, int> data[1000000];
    int max1 = 1000000000;
    int max2 = 1000000000;
    int length = a.size() - 1;
    for (int i = 0; i <= length; ++i)
    {
        data[i].first = max1;
        max1 = min(max1, a[i]);
        data[length - i].second = max2;
        max2 = min(max2, a[length - i]);
    }
    for (int i = 0; i < a.size(); ++i)
    {
        if (false == bLastBalloon(a, data, i)) continue;
        answer++;
    }

    return answer;
}