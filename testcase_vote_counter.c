#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define NUM_TESTCASE 10

int vote_counter(FILE* fp) {
	int a = 0, b = 0, c = 0, n = 0, res=0;
	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		int temp = 0;
		fscanf(fp, "%d", &temp);

		if (temp == 1)a++;
		else if (temp == 2)b++;
		else c++;
	}

	if (a == b || a == c || b == c) return 0;

	if (a > b) {
		if (a > c)res=1;
		else res=3;
	}
	else if (b > a) {
		if (b > c)res=2;
		else res=3;
	}

	return res;
}

void gen_testcase(char in_dir[], char out_dir[], int i) {
	int n = rand() % 100 + 1;

	FILE* fp1 = fopen(in_dir, "w");

	fprintf(fp1, "%d\n", n);
	for (int i = 0; i < n; i++) {
		int r = rand() % 3 + 1;
		fprintf(fp1, "%d\n", r);
	}

	fclose(fp1);
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < NUM_TESTCASE; i++) {

		char in_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_vote_counter/000";
		char out_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_vote_counter/000";
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