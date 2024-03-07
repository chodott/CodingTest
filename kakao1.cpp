#include <string>
#include <set>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> str1_ms;
    multiset<string> str2_ms;
    set<string> intersection_set;

    bool bAlpha = 1;
    for (int i = 0; i < str1.size(); ++i)
    {
        if (65 > str1[i] || (str1[i] > 90 && str1[i] < 97) || str1[i] > 122)
        {
            bAlpha = 0;
        }
        else
        {
            if (i > 0 && bAlpha)
            {
                string temp = str1.substr(i - 1, 2);
                str1_ms.insert(temp);
            }
            bAlpha = 1;
        }
    }

    for (int i = 0; i < str2.size(); ++i)
    {
        if (65 > str2[i] || (str2[i] > 90 && str2[i] < 97) || str2[i] > 122)
        {
            bAlpha = 0;
        }
        else
        {
            if (i > 0 && bAlpha)
            {
                string temp = str2.substr(i - 1, 2);
                str2_ms.insert(temp);
                if (str1_ms.end() != str1_ms.find(temp))
                {
                    intersection_set.insert(temp);
                }
            }
            bAlpha = 1;
        }
    }

    answer = (int)(intersection_set.size() / (str1_ms.size() + str2_ms.size()) * 65536);


    return answer;
}

int main()
{
    solution("dddddd", "dddddddd")
}