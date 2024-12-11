#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define NUM_TESTCASE 10
#define N_SIZE 100
#define M_SIZE 1000

int vote_counter(FILE* fp) {
	int candidates[N_SIZE] = { 0 }, n = 0, m = 0, winner = 0;
	fscanf(fp, "%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int temp = 0;
		fscanf(fp, "%d", &temp);
		candidates[temp]++;
	}


	for (int i = 0; i < n; i++) {
		if (candidates[winner] < candidates[i])winner = i;
	}
	for (int i = 0; i < n; i++) {
		if (i!=winner && candidates[i] == candidates[winner])return 0;
	}

	return winner;
}

void gen_testcase(char in_dir[], char out_dir[], int i) {
	int n = rand() % N_SIZE + 1, m=rand()%M_SIZE+1;

	FILE* fp1 = fopen(in_dir, "w");

	fprintf(fp1, "%d %d\n", n, m);
	for (int i = 0; i < m; i++) {
		int r = rand() % n;
		fprintf(fp1, "%d\n", r);
	}

	fclose(fp1);
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < NUM_TESTCASE; i++) {

		char in_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_N_candidates/000";
		char out_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_N_candidates/000";
		char in_index[10] = "";
		char out_index[10] = "";
		in_index[0] = i + '0';
		out_index[0] = i + '0';
		strcat(in_index, ".in");
		strcat(out_index, ".out");
		strcat(in_dir, in_index);
		strcat(out_dir, out_index);

		int vote_equal = 1;

		while (vote_equal) {
			gen_testcase(in_dir, out_dir, i);

			FILE* fp2 = fopen(in_dir, "r");
			int res = vote_counter(fp2);
			fclose(fp2);
			if (res > 0) {
				FILE* fp3 = fopen(out_dir, "w");
				fprintf(fp3, "%d", res);
				fclose(fp3);

				vote_equal = 0;
			}

		}


	}
}