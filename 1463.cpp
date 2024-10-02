#include <iostream>
#define INF 987654321
using namespace std;

int main()
{
	int n; cin >> n;
	int minCalculation[1000001];
	fill(&minCalculation[0], &minCalculation[1000001], INF);
	minCalculation[1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		minCalculation[i + 1] = min(minCalculation[i + 1], minCalculation[i] + 1);
		if (i * 2 <= n) minCalculation[i * 2] = min(minCalculation[i * 2], minCalculation[i] + 1);
		if (i * 3 <= n) minCalculation[i * 3] = min(minCalculation[i * 3], minCalculation[i] + 1);
	}
	cout << minCalculation[n];
}