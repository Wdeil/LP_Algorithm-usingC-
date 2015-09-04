/*
calculate the value of (Fn % 10000).
Fn is the Nth Fibonacci.
*/

#include <stdio.h>

int main() {
	int a, b, t, i, n, q;
	scanf("%d", &q);
	while(q) {
		scanf("%d", &n);
		for (i = 0, a = 1, b = 0; i < n; i++) {
			t = a;
			a = (a + b) % 10000;
			b = t;
		}
		printf("%d", b);
		if (--q)
			printf("\n");
	}
	return 0;
}
