#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer ={0,0};
    char lastChar = words[0][0];
    unordered_set<string> word_set;
    for(int count =0; count < words.size(); ++count)
    {
        string& word = words[count];
        if(word_set.find(word) != word_set.end()
          ||lastChar != word[0]) return {count%n+1, count/n+1}; 
        lastChar = word.back();
        word_set.insert(word);
    }

    return answer;
}