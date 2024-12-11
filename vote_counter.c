#include <stdio.h>

int main() {
	int a = 0, b = 0, c = 0, n=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int temp = 0;
		scanf("%d", &temp);

		if (temp == 1)a++;
		else if (temp == 2)b++;
		else c++;
	}

	if (a > b) {
		if (a > c)printf("1");
		else printf("3");
	}
	else {
		if (b > c)printf("2");
		else printf("3");
	}

	return 0;
}