#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer;
    int index =0;
    for(int i=0;i<number.length();++i)
    {
        if(answer.length() == 0 || answer.back() >= number[i]) 
        {
            answer.push_back(number[i]);
            continue;
        }
        else
        {
            if(k<=0) 
            {
                answer.append(number.begin()+i, number.end());
                break;
            }
            answer.pop_back();
            --i;
            k--;
        }
    }
    if(k>0) answer = answer.substr(0, answer.length()-k);
    return answer;
}