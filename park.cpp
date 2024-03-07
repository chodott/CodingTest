#include <string>
#include <vector>
#include <iostream>
//우선순위 d->l->r->y
using namespace std;

string returnRoad(int n, int m, int r, int c, int x, int y, int k, int length, string road)
{
    if (k == length && x == r && y == c) return road;
    else if (k == length) return "";
    if (x > n || y > m || x < 1 || y < 1) return "";
    string answer;
    answer = returnRoad(n, m, r, c, x+1, y , k, length + 1, road + "d");
    if (answer.length() == k) return answer;
    answer = returnRoad(n, m, r, c, x, y-1, k, length + 1, road + "l");
    if (answer.length() == k) return answer;
    answer = returnRoad(n, m, r, c, x, y+1, k, length + 1, road + "r");
    if (answer.length() == k) return answer;
    answer = returnRoad(n, m, r, c, x-1, y, k, length + 1, road + "u");
    if (answer.length() == k) return answer;

}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    answer = returnRoad(n, m, r, c, x, y, k, 0, "");
    cout << answer;
    return answer;
}

int main()
{
    solution(3,3,1,2,3,3,4);
}