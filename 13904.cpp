#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	bool bChecked[1001];
	fill(&bChecked[0], &bChecked[1001], false);
	priority_queue<pair<int, int>> data_pq;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int d, w;
		cin >> d >> w;
		data_pq.push({ w,d });
	}

	while (!data_pq.empty())
	{
		int point = data_pq.top().first;
		int deadline = data_pq.top().second;
		data_pq.pop();

		while (bChecked[deadline]) deadline--;

		if (deadline == 0) continue;
		bChecked[deadline] = true;
		sum += point;
	}
	cout << sum;
}