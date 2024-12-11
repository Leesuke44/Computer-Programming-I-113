#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() {
    float x;
    int N;
    scanf("%f%d", &x, &N);

    float cos = 1, tmp = 1;
    for (int i = 1; i <= N; i++) {
        tmp *= -1 * (x * x) / ((2 * i - 1) * (2 * i));
        cos += tmp;
    }

    printf("%.6f\n", cos);


    float sinx = 0;
    float temp2 = x;
    for (int n = 0; n <= N; n++) {
        sinx += temp2;
        temp2 *= -x * x / ((2 * n + 2) * (2 * n + 3));  // 更新至下一項
    }

    printf("%.6f\n", sinx);

    return 0;

}