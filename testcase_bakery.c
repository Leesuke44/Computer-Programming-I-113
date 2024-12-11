#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define NUM_TESTCASE 6

#define Price 100
#define NumOfRMOrCust 1000
#define NumOfProduct 5
#define NumOfRawMaterial 6

int produce(int rm1, int rm2, int rm3) {
	int res = 0;
	res = rm1 < rm2 / 2 ? rm1 : rm2 / 2;
	res = res < rm3 / 3 ? res : rm3 / 3;
	return res;
}

int checkout(FILE* fp, int total1, int total2, int price1, int price2, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		fscanf(fp, "%d%d", &num1, &num2);
		num1 = num1 <= total1 ? num1 : total1;
		num2 = num2 <= total2 ? num2 : total2;
		res += (num1 * price1 + num2 * price2);
		total1 -= num1;
		total2 -= num2;
	}

	return res;
}

int bakery(FILE* fp) {
	int rawMaterials[NumOfRawMaterial], breadPrice, cakePrice, N, breads, cakes, income;
	for (int i = 0; i < NumOfRawMaterial; i++) {
		fscanf(fp, "%d", &rawMaterials[i]);
	}
	fscanf(fp, "%d%d", &breadPrice, &cakePrice);
	fscanf(fp, "%d", &N);

	breads = produce(rawMaterials[0], rawMaterials[1], rawMaterials[2]);
	cakes = produce(rawMaterials[3], rawMaterials[4], rawMaterials[5]);

	income = checkout(fp, breads, cakes, breadPrice, cakePrice, N);

	return income;

}

void gen_testcase(char in_dir[], char out_dir[], int i) {
	FILE* fp1 = fopen(in_dir, "w");

	for (int i = 0; i < 3; i++) {
		int rm = rand() % NumOfRMOrCust;
		fprintf(fp1, "%d ", rm);
	}
	fprintf(fp1, "\n");
	for (int i = 0; i < 3; i++) {
		int rm = rand() % NumOfRMOrCust;
		fprintf(fp1, "%d ", rm);
	}
	fprintf(fp1, "\n");

	for (int i = 0; i < 2; i++) {
		int p = rand() % Price + 1;
		fprintf(fp1, "%d ", p);
	}
	fprintf(fp1, "\n");
	
	int n = rand() % NumOfRMOrCust + 1;
	fprintf(fp1, "%d\n", n);

	for (int i = 0; i < n; i++) {
		int t1 = rand() % NumOfProduct, t2 = rand() % NumOfProduct;
		fprintf(fp1, "%d %d\n", t1, t2);
	}

	fclose(fp1);
}

int main() {
	srand(time(NULL));

	for (int i = 0; i < NUM_TESTCASE; i++) {

		char in_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_bakery/000";
		char out_dir[100] = "C:/Users/abc89/OneDrive/文件/碩課/TA_CP I/testcase_bakery/000";
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
		int res = bakery(fp2);
		fclose(fp2);

		FILE* fp3 = fopen(out_dir, "w");
		fprintf(fp3, "%d", res);
		fclose(fp3);




	}
}