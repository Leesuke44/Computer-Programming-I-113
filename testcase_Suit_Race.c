#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_TESTCASE 10
#define N_SIZE 48
#define FinishLine 5
char Suits[4][10] = { "Spade", "Heart", "Diamond", "Club" };

bool stage_check(int arr[], int stage) {
	bool res = true;
	for (int i = 0; i < 4; i++) {
		if (arr[i] < stage)res = false;
	}
	return res;
}

int is_anyone_wins(int arr[]) {
	int res = -1;
	for (int i = 0; i < 4; i++) {
		if (arr[i] == FinishLine)res = i;
	}
	return res;
}

int suit_race(FILE* fp) {
	int  aces[4] = { 0 }, winner = 0, stage[4] = { 0 }, curStage = 1;

	for (int i = 0; i < 4; i++) {
		int dummy = 0;
		fscanf(fp, "%d %d", &stage[i], &dummy);
	}
	winner = is_anyone_wins(aces);

	while (winner==-1) {
		int s = 0, dummy = 0;
		fscanf(fp, "%d %d", &s, &dummy);
		aces[s]++;

		if (stage_check(aces, curStage)) {
			aces[stage[curStage]]--;
			curStage++;
		}
		winner = is_anyone_wins(aces);
	}

	printf("%s", Suits[winner]);
	return winner;
}

void gen_testcase(char in_dir[], char out_dir[], int i) {
	bool card[N_SIZE] = { false };
	FILE* fp1 = fopen(in_dir, "w");

	for (int i = 0; i < N_SIZE; i++) {
		int n = rand() % N_SIZE;
		while (card[n]) {
			n = rand() % N_SIZE;
		}
		card[n] = true;
		int suit = n / 12, val = n % 12+2;
		fprintf(fp1, "%d %d\n", suit, val);
	}

	fclose(fp1);
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < NUM_TESTCASE; i++) {

		char in_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_suit_race/000";
		char out_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_suit_race/000";
		char in_index[10] = "";
		char out_index[10] = "";
		in_index[0] = i + '0';
		out_index[0] = i + '0';
		strcat(in_index, ".in");
		strcat(out_index, ".out");
		strcat(in_dir, in_index);
		strcat(out_dir, out_index);


		gen_testcase(in_dir, out_dir, i);

		FILE* fp2 = fopen(in_dir, "r");
		int res = suit_race(fp2);
		fclose(fp2);
		if (res >= 0) {
			FILE* fp3 = fopen(out_dir, "w");
			fprintf(fp3, "%s", Suits[res]);
			fclose(fp3);

		}



	}
}