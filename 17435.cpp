#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_LOG 20
int main()
{
	int data[MAX_LOG][200001];
	int m, q;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", data[0][i]);

	for (int i = 1; i < MAX_LOG; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int next = data[i - 1][j];
			data[i][j] = data[i - 1][next];
		}
	}

	scanf("%d", &q);
	while(q--)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		
		for (int k = MAX_LOG-1; k >= 0; --k)
		{
			if (n & (1 << k))		
			{	//��Ʈ �������� n�� �Ϻΰ� �Ǵ� 2�� ���� ������ �ε��� ����
				x = data[k][x];
			}
		}
		printf("%d\n", x);
	}
}