#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int,int> leftMap;
    unordered_map<int,int> rightMap;
    
    for(int value : topping) 
    {
        if(rightMap.find(value) == rightMap.end()) rightMap[value] = 1;
        else rightMap[value]++;
    }
    
    for(int value : topping)
    {
        if(leftMap.find(value) == leftMap.end()) leftMap[value] = 1;
        else leftMap[value]++;
        
        if(rightMap.find(value) != rightMap.end()) 
        {
            rightMap[value]--; 
            if(rightMap[value] == 0) rightMap.erase(value);
        }
        if(leftMap.size() == rightMap.size()) answer++;
    }
    
    return answer;
}