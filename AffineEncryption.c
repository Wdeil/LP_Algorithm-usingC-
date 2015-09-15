#include <stdio.h>

#define mod 26

int InverseEasy(int ke1) {
	int i = 0;
	while((ke1 * (++i) % mod) != 1);
	return i;
}

char AffineEn(char plaintext, int ke1, int ke2) {
	if(plaintext > 96 && plaintext < 123)
		return ((plaintext - 97) * ke1 + ke2) % mod + 97;
	else if (plaintext > 64 && plaintext < 91)
		return ((plaintext - 65) * ke1 + ke2) % mod + 65;
	else
		return plaintext;
}

char AffineDe(char ciphertext, int ke1, int ke2) {
	int kd1 = InverseEasy(ke1);
	if(ciphertext > 96 && ciphertext < 123) {
		int t = ((ciphertext - 97 - ke2) * kd1);
		while(t < 0)
			t += mod; 
		return t % mod + 97;
	}
	else if (ciphertext > 64 && ciphertext < 91) {
		int t = ((ciphertext - 65 - ke2) * kd1);
		while(t < 0)
			t += mod; 
		return t % mod + 65;
	}
	else
		return ciphertext;
}

int* KeyCrack(char p1, char p2, char c1, char c2) {
	/*int k[2] = {0, 0};
	return k;*/
}

int main() {
	int t = 0;
	printf("Welcome to Affine Encryption.\n");
	while(t != 4) {
		printf("1: Affine Encode;\n2: Affine Decode;\n3: Find out unknown key;\n4: Exit.\nPlease enter your choice: ");
		scanf("%d", &t);
		if(t == 1) {
			int ke1, ke2;
			char plaintext;
			printf("Please enter key1, key2 (Sepqrated by a space): ");
			scanf("%d %d", &ke1, &ke2);
			printf("Please enter the string which you want to encode: ");
			getchar();
			while ((plaintext = getchar()) != '\n')
				printf("%c", AffineEn(plaintext, ke1, ke2));
			printf("\n");
		}
		else if (t == 2) {
			int ke1, ke2;
			char ciphertext;
			printf("Please enter key1, key2 (Sepqrated by a space): ");
			scanf("%d %d", &ke1, &ke2);
			printf("Please enter the string which you want to decode: ");
			getchar();
			while ((ciphertext = getchar()) != '\n')
				printf("%c", AffineDe(ciphertext, ke1, ke2));
			printf("\n");
		}
		else if (t == 3) {
			int *k;
			char p1, p2, c1, c2;
			printf("Please enter the plaintext and ciphertext(Sepqrated by a space and only need two char): ");
			p1 = getchar();
			p2 = getchar();
			getchar();
			c1 = getchar();
			c2 = getchar();
			k = KeyCrack(p1, p2, c1, c2);
			printf("the key1 is %d, the key2 is %d.\n", k[0], k[1]);
		}
	}
	return 0;
}
