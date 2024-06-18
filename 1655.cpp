#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int center=0;
	priority_queue<int> down_pq;
	priority_queue<int, vector<int>, greater<int>> up_pq;
	cin >> center; cout << center<<"\n";
	for(int i=1;i<n;++i)
	{
		int num;  cin >> num;
		if (center <= num) up_pq.push(num);
		else down_pq.push(num);
		int dist = up_pq.size() - down_pq.size();
		if (dist < 0)
		{
			up_pq.push(center);
			center = down_pq.top();
			down_pq.pop();
		}
		else if(dist > 1)
		{
			down_pq.push(center);
			center = up_pq.top();
			up_pq.pop();
		}
		cout <<center << "\n";
	}
}