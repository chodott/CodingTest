//첫번째 코드
//루트 함수부터 하위 노드를 체크하는 재귀함수 작성 후 문제풀이
//정확성은 좋으나 시간이 오래걸림..!
#include <string>
#include <vector>
#include <deque>

// 왼쪽 -> 오른쪽.
// 말단 노드가 아니면 0이 될 수 없다.!
// 루트가 0이면 불가능
using namespace std;

bool returnPossible(string& binary, int index, int gap)
{
    if (gap < 1) return true;
    int prev = index - gap;
    int next = index + gap;
    if (binary[index - 1] == '0' &&
        ((binary[prev - 1]) == '1' || (binary[next - 1]) == '1')) return false;
    else
    {
        if (!returnPossible(binary, prev, gap / 2)) return false;
        if (!returnPossible(binary, next, gap / 2)) return false;
    }
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto& number : numbers)
    {
        string binary = "";
        while (number >= 1)
        {
            binary += (number % 2 == 0) ? "0" : "1";
            number /= 2;
        }
        //포화 트리 수로 맞추기
        int n = 1;
        while (n < binary.size()) n *= 2;
        while (binary.size() != n - 1) binary += "0";
        int root = n / 2;
        answer.emplace_back(returnPossible(binary, root, root / 2));
    }
    return answer;
}