#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<pair<int, int>> stairs(n + 1, { 0,0});
	cin >> stairs[1].first;
	for (int i = 2; i <= n; ++i)
	{
		int value; cin >> value;

		stairs[i].first = max(stairs[i - 2].first, stairs[i - 2].second) + value;
		stairs[i].second = stairs[i - 1].first + value;
	}

	cout << (stairs[n].first < stairs[n].second ? stairs[n].second : stairs[n].first);
}


//���̳��� ���α׷����� ���� ������ Ǯ����/

/*
1. ����� �������� �Է� �޴´�.
2. �� ��ܿ��� �ִ� ������ stairs �迭�� �����Ѵ�.
stairs �迭���� �ش� ����� ������ �ݿ����� ���� �ִ밪�� �����ϴµ�
�迭�� ����Ǵ� �ڷ����� pair�� �ۼ��Ͽ�
�� ��� ������ ���� ����� �ִ������� �ٷ� ���� ��ܿ��� ���� �����
�ִ������� ������ ǥ���ϱ� �����̴�.

������ ��ܿ��� stairs[n].first�� second���� ���ϸ� 
���� �����س� �� �ִ�.
*/