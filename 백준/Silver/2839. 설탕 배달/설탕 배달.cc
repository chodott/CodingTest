#include <stdio.h>
int main(void) {
	int n,bomin=0;
	scanf("%d", &n);
	for (int i = 0; i <= 1670; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (n == 3 * i + 5 * j) {
				bomin = i + j;
				break;
			}
		}
		if (bomin != 0) break;
	}
	if (bomin != 0) printf("%d", bomin);
	else printf("-1");
}