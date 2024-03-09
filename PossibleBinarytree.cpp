//ù��° �ڵ�
//��Ʈ �Լ����� ���� ��带 üũ�ϴ� ����Լ� �ۼ� �� ����Ǯ��
//��Ȯ���� ������ �ð��� �����ɸ�..!
#include <string>
#include <vector>
#include <deque>

// ���� -> ������.
// ���� ��尡 �ƴϸ� 0�� �� �� ����.!
// ��Ʈ�� 0�̸� �Ұ���
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
        //��ȭ Ʈ�� ���� ���߱�
        int n = 1;
        while (n < binary.size()) n *= 2;
        while (binary.size() != n - 1) binary += "0";
        int root = n / 2;
        answer.emplace_back(returnPossible(binary, root, root / 2));
    }
    return answer;
}