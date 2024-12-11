#include <stdio.h>
#define NumOfRawMaterial 6

int produce(int rm1, int rm2, int rm3) {
	int res = 0;
	res = rm1 < rm2 / 2 ? rm1 : rm2 / 2;
	res = res < rm3 / 3 ? res : rm3 / 3;
	return res;
}

int checkout(int total1, int total2, int price1, int price2, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		scanf("%d%d", &num1, &num2);
		num1 = num1 <= total1 ? num1 : total1;
		num2 = num2 <= total2 ? num2 : total2;
		res += (num1 * price1 + num2 * price2);
		total1 -= num1;
		total2 -= num2;
	}

	return res;
}

int main() {
	int rawMaterials[NumOfRawMaterial], breadPrice, cakePrice, N, breads, cakes, income;
	for (int i = 0; i < NumOfRawMaterial; i++) {
		scanf("%d", &rawMaterials[i]);
	}
	scanf("%d%d", &breadPrice, &cakePrice);
	scanf("%d", &N);

	breads = produce(rawMaterials[0], rawMaterials[1], rawMaterials[2]);
	cakes = produce(rawMaterials[3], rawMaterials[4], rawMaterials[5]);

	income = checkout(breads, cakes, breadPrice, cakePrice, N);

	printf("%d", income);

}