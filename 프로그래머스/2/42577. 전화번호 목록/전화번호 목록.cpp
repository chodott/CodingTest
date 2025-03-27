#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//트라이 
using namespace std;

class Node
{
    public:
    int num;
    bool done = false;
    vector<Node*> node_vec;
    Node() : node_vec(10, nullptr) {} 
};

bool compare(string& s1, string& s2)
{
    return s1.length() < s2.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    Node* root = new Node();
    Node* curNode;
    sort(phone_book.begin(), phone_book.end(), compare);
    for(string& phone:phone_book)
    {
        curNode = root;
        int index;         
        for(int i=0;i<phone.length(); ++i)
        {
            index = phone[i] -'0';
            if(curNode->node_vec[index] == NULL) curNode->node_vec[index] = new Node();
            if(curNode->node_vec[index]->done) return false;
            if(i == phone.length()-1) curNode->node_vec[index]->done = true;
            curNode = curNode->node_vec[index];
        }
    }
    return answer;
}