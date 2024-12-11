#include <stdio.h>
#define SIZE 1000
int main() {
	int cities[SIZE], numCities = 0, numOp=0;

	scanf("%d %d", &numCities, &numOp);

	for (int i = 0; i < numCities; i++) {
		scanf("%d", &cities[i]);
	}

	for (int i = 0; i < numOp; i++) {
		int start = 0, end = 0, amount = 0, recover=0;
		scanf("%d %d %d", &start, &end, &amount);
		start -= 1, end -= 1;
		for (int j = start; j <= end; j++) {
			cities[j] += amount;
			//???
			if (cities[j] <= 0)recover = 1;
		}

		if (recover) {
			for (int j = start; j <= end; j++) {
				cities[j] -= amount;
			}
		}
	}
	
	for (int i = 0; i < numCities; i++)printf("%d ", cities[i]);
}