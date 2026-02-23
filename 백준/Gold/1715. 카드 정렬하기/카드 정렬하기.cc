#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> cardpack_pq;
	int n;
	int sum =0;
	int answer = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i=0; i<n; ++i)
	{
		int cardpack;
		cin >> cardpack;
		cardpack_pq.push(cardpack);
	}

	while (cardpack_pq.size() > 1)
	{
		sum = cardpack_pq.top();
		cardpack_pq.pop();
		sum += cardpack_pq.top();
		cardpack_pq.pop();
		cardpack_pq.push(sum);
		answer += sum;
	}
	cout << answer;
}