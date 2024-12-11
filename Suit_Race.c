#include <stdio.h>
#include <stdbool.h>
#define FinishLine 5

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

int main() {
	int  aces[4] = { 0 }, winner = 0, stage[4] = {0}, curStage = 1;
	char Suits[4][10] = { "Spade", "Heart", "Diamond", "Club" };

	for (int i = 0; i < 4; i++) {
		int dummy = 0;
		scanf("%d %d", &stage[i], &dummy);
	}
	winner = is_anyone_wins(aces);

	while (winner==-1) {
		int s = 0, dummy = 0; 
		scanf("%d %d", &s, &dummy);
		aces[s]++;

		if (stage_check(aces, curStage)) {
			//aces[stage[curStage]] = aces[stage[curStage]] == 0 ? 0:aces[stage[curStage]]--;
			aces[stage[curStage]]--;
			curStage++;
		}

		winner = is_anyone_wins(aces);
	}

	printf("%s", Suits[winner]);
}