#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wish_um;
    for(int i=0;i<want.size();++i) wish_um[want[i]] = -number[i];
    for(int i=0;i<discount.size();++i)
    {
        bool bSuccess = true;
        wish_um[discount[i]]++;
        if(i>=10)wish_um[discount[i-10]]--;
        for(int j=0;j<want.size();++j)
        {
            if(wish_um[want[j]]>=0) continue;
            bSuccess = false;
            break;
        }
        if(bSuccess) answer++;
    }

    return answer;
}