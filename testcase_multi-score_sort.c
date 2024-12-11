#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_TESTCASE 4
#define N_SIZE 50
#define SCORE 101
int sort(char in_dir[], char out_dir[]) {
	int N = 0, arr[N_SIZE][4];

	FILE* fp2 = fopen(in_dir, "r");

	fscanf(fp2, "%d", &N);
	for (int i = 0; i < N; i++) {
		fscanf(fp2, "%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}

	fclose(fp2);

	for (int i = N - 1; i > 0; i--) {
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

	FILE* fp3 = fopen(out_dir, "w");

	for (int i = 0; i < N; i++) {
		fprintf(fp3, "%d ", arr[i][0]);
	}

	fclose(fp3);

	return 1;
}

void gen_testcase_norepeated(char in_dir[], char out_dir[], int i) {
	int n = rand() % N_SIZE + 1;

	FILE* fp1 = fopen(in_dir, "w");

	fprintf(fp1, "%d\n", n);
	bool used[3][SCORE] = { false };
	for (int i = 0; i < n; i++) {
		int id = i, score1 = rand() % SCORE, score2 = rand() % SCORE, score3 = rand() % SCORE;

		while (used[0][score1] || used[1][score2] || used[2][score3]) {
			score1 = rand() % SCORE + 1, score2 = rand() % SCORE + 1, score3 = rand() % SCORE + 1;
		}
		used[0][score1] = true, used[1][score2] = true, used[2][score3] = true;

		fprintf(fp1, "%d %d %d %d\n", id, score1, score2, score3);
	}

	fclose(fp1);
}

void gen_testcase_repeated(char in_dir[], char out_dir[], int i) {
	int n = N_SIZE;

	FILE* fp1 = fopen(in_dir, "w");

	fprintf(fp1, "%d\n", n);
	bool used[SCORE] = { false };
	for (int i = 0; i < n; i++) {
		int id = i, score1 = rand() % SCORE, score2 = rand() % SCORE, score3 = rand() % SCORE;

		while (used[score3]) {
			score1 = rand() % SCORE + 1, score2 = rand() % SCORE + 1, score3 = rand() % SCORE + 1;
		}
		used[score3] = true;

		fprintf(fp1, "%d %d %d %d\n", id, score1, score2, score3);
	}

	fclose(fp1);
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < NUM_TESTCASE; i++) {

		char in_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_multi-score_sort/010";
		char out_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_multi-score_sort/010";
		char in_index[10] = "";
		char out_index[10] = "";
		in_index[0] = i + '0';
		out_index[0] = i + '0';
		strcat(in_index, ".in");
		strcat(out_index, ".out");
		strcat(in_dir, in_index);
		strcat(out_dir, out_index);


		gen_testcase_repeated(in_dir, out_dir, i);

		int res = sort(in_dir, out_dir);

	}
}