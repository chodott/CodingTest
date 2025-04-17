#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> categoryCnt_map;
    for(auto& cloth : clothes) categoryCnt_map[cloth[1]]++;
    for(auto& category: categoryCnt_map)answer *= (category.second + 1);
    return answer -1;
}