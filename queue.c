#include<stdio.h>

#define N_SIZE 10
#define M_SIZE 1000
#define MAX 100000000
int main() {
	int numCounters = 0, numCustomers = 0, arrival[M_SIZE] = { 0 }, time[M_SIZE], counter[N_SIZE] = {0}, res = 0;

	scanf("%d%d", &numCounters, &numCustomers);

	for (int i = 0; i < numCustomers; i++) {
		scanf("%d", &arrival[i]);
	}

	for (int i = 0; i < numCustomers; i++) {
		scanf("%d", &time[i]);
	}
	
	for (int i = 0; i < numCustomers; i++) {
		int min = 0;
		for (int j = 0; j < numCounters; j++) {
			if (counter[j] < counter[min])min = j;
		}

		int t = counter[min] - arrival[i];
		if (t <= 0) {
			counter[min] = arrival[i] + time[i];
		}
		else {
			res += t;
			counter[min] += time[i];
		}
	}

	printf("%d", res);
}