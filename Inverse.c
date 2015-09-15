#include <stdio.h>

#define mod 26

int InverseEasy(int ke1) {
	int i = 0;
	while((ke1 * (++i) % mod) != 1);
	return i;
}

int main() {
	int t;
	printf("Please enter the number which you want to solving inverse: ");
	scanf("%d", &t);
	printf("%d\n", InverseEasy(t));
	return 0;
}
