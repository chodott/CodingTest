//1927번, 11286번  동시에 풀었읍니다~
#include <iostream>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;

		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	// 11279번 priority_queue<int, vector<int>, less<int>> greater_pq;
	priority_queue<int, vector<int>, compare> greater_pq;
	while (n--)
	{
		int x; cin >> x;
		if (x == 0)
		{
			if (greater_pq.empty()) cout << "0" << "\n";
			else
			{
				cout << greater_pq.top() << "\n";
				greater_pq.pop();
			}
			//max 출력
		}
		else greater_pq.push(x);
	}
}