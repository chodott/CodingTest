#include <iostream>
#include <vector>
using namespace std;

// 40까지의 피보나치 함수를 통해 0과1이 호출된 횟수를 미리 구한다.
// 테스트 케이스를 반복하면서 출력만한다.

pair<int,int> fibonacci(int n, vector<pair<int,int>>& printCnt_vec) 
{
    if (n == 0) {
        return { 1,0 };
    }
    else if (n == 1) {
        return { 0,1 };
    }
    else {
        return make_pair(printCnt_vec[n - 1].first + printCnt_vec[n - 2].first,
            printCnt_vec[n - 1].second + printCnt_vec[n - 2].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    vector<pair<int, int>> printCnt_vec(41, { 0,0 });
    for (int i = 0; i <= 40; ++i) 
        printCnt_vec[i] = fibonacci(i, printCnt_vec);
	while (t--)
	{
		int n; cin >> n;
        cout << printCnt_vec[n].first << " " << printCnt_vec[n].second << "\n";
	}

}
