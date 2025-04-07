#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> answer_set;
    int sum =0;
    for(int element:elements) sum+=element;
    for(int i=0; i<elements.size(); ++i)
    {
        for(int index=0; index<elements.size() - i; ++index)
        {
            int value = accumulate(elements.begin()+index, elements.begin()+index+i,0);
            int value2= sum - value;
            answer_set.insert(value);
            answer_set.insert(value2);
        }
    }
    return answer_set.size()-1;
}