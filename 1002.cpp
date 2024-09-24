#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int x1, y1, r1, x2, y2, r2; 
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double gap = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1;
		else if (gap == r1 + r2 || gap == abs(r1 - r2)) cout << 1;
		else if (gap > r1 + r2 || gap < abs(r1 - r2)) cout << 0;
		else cout << 2;
		cout << "\n";
	}
 }