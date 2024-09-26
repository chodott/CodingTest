#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;

	
	int cupCnt = 0;
	while (1)
	{
		int cnt = bitset<24>(n + cupCnt).count();
		if (cnt <= k)
		{
			cout << cupCnt;
			return 0;
		}
		cupCnt++;
	}
	cout << -1;
}