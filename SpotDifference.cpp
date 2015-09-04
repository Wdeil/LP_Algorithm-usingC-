/*=========================================================
find out the Element which only appears once in the list given.
the list's element is Non-negative.
=========================================================*/

#include <stdio.h>
#include <malloc.h>

int main() {
	int n, t, i;
	int *x = (int*)malloc(n*sizeof(int));
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	t = x[0];
	for (i = 1; i < n; i++) {
		t = t^x[i];
	}
	printf("%d", t);
	return 0;
}
