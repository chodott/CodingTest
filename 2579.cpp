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


//다이나믹 프로그래밍을 통해 문제를 풀이함/

/*
1. 계단의 점수값을 입력 받는다.
2. 각 계단에서 최대 점수를 stairs 배열에 저장한다.
stairs 배열에는 해당 계단의 점수를 반영했을 때의 최대값을 저장하는데
배열에 저장되는 자료형을 pair로 작성하여
두 계단 전에서 오는 경우의 최대점수와 바로 이전 계단에서 오는 경우의
최대점수를 나눠서 표현하기 위함이다.

마지막 계단에서 stairs[n].first와 second값만 비교하면 
답을 도출해낼 수 있다.
*/