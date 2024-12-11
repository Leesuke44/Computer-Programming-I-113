#include <stdio.h>
#define SIZE 100
int main() {
	int candidates[SIZE] = {0}, n = 0, m = 0, winner=0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int temp = 0;
		scanf("%d", &temp);
		candidates[temp]++;
	}

	for (int i = 0; i < n; i++) {
		if (candidates[winner] < candidates[i])winner = i;
	}

	printf("%d", winner);
	return 0;
}