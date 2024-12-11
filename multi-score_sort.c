#include <stdio.h>
#define SIZE 50
int main() {
	int N = 0, arr[SIZE][4];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}

	for (int i = N-1; i>0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j][1] < arr[j + 1][1]) {
				for (int k = 0; k < 4; k++) {
					int tmp = arr[j][k];
					arr[j][k] = arr[j + 1][k];
					arr[j + 1][k] = tmp;
				}
			}
		}
	}
	int left = 0, right = 1;
	while (right < N) {
		if (arr[left][1] == arr[right][1]) {
			while (right < N - 1 && arr[right][1] == arr[right + 1][1])right++;
			for (int i = right; i > 0; i--) {
				for (int j = left; j < i; j++) {
					if (arr[j][2] < arr[j + 1][2]) {
						for (int k = 0; k < 4; k++) {
							int tmp = arr[j][k];
							arr[j][k] = arr[j + 1][k];
							arr[j + 1][k] = tmp;
						}
					}
				}
			}
		}
		

		left = right;
		right++;
	}

	left = 0, right = 1;
	while (right < N) {
		if (arr[left][2] == arr[right][2]) {
			while (right < N - 1 && arr[right][2] == arr[right + 1][2])right++;
			for (int i = right; i > 0; i--) {
				for (int j = left; j < i; j++) {
					if (arr[j][3] < arr[j + 1][3]) {
						for (int k = 0; k < 4; k++) {
							int tmp = arr[j][k];
							arr[j][k] = arr[j + 1][k];
							arr[j + 1][k] = tmp;
						}
					}
				}
			}
		}
		

		left = right;
		right++;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i][0]);
	}
}