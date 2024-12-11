#include <stdio.h>

#define RL 9  // row length
#define CL 9  // col length

int DupNumInArr(int* a, int* count, int length);

int main() {
    // 0. build s array
    int s[CL][RL] = { 0 };

    for (int i = 0; i < CL; i++) {
        for (int j = 0; j < RL; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    int dupNum = 0;
    int count[10] = { 0 };

    // 1. find duplicated num
    // 1.1 check duplicated num in each colm, if print + return
        // for each colmj: make col arr, has dupNum?, print and rt
    int col[CL] = { 0 };
    for (int j = 0; j < RL; j++) {
        // make col arr
        for (int i = 0; i < CL; i++) {
            col[i] = s[i][j];
        }

        // get dupNum in each col arr
        dupNum = DupNumInArr(col, count, CL);

        // if dupNum != 0, find and print (rowi, coli), rt
        if (dupNum != 0) {
            for (int i = 0; i < CL; i++) {
                if (s[i][j] == dupNum) {
                    printf("%d %d\n", i, j);
                }
            }
            return 1;
        }

    } //End 1.1. for ROWj, find dupNum in each row, if any, rt

// 1.2. check duplicated num in each row, if print + rt
    // for each rowi: make row arr, has dupNum?, print and rt
    int row[RL] = { 0 };
    for (int i = 0; i < CL; i++) {
        // make row arr
        for (int j = 0; j < RL; j++) {
            row[j] = s[i][j];
        }

        // get dupNum in each col arr
        dupNum = DupNumInArr(row, count, RL);

        // if dupNum != 0, find and print (rowi, coli), rt
        if (dupNum != 0) {
            for (int j = 0; j < RL; j++) {
                if (s[i][j] == dupNum) {
                    printf("%d %d\n", i, j);
                }
            }
            return 1;
        }

    } //End 1.2. for COLi, find dupNum in each row, if any, rt


// 3. for each 3*3, see if any duplicated, if print + rt
    int small33[9] = { 0 };
    int smi = 0; // small33 index

    for (int i = 0; i < CL; i += 3) {
        for (int j = 0; j < RL; j += 3) {
            // Now we're in each small 3*3 with index 00, 03, 06; 30 33 36...
            // 1. make 3*3 an small33 array
            smi = 0;
            for (int i_ = i; i_ < i + 3; i_++) {
                for (int j_ = j; j_ < j + 3; j_++) {
                    small33[smi] = s[i_][j_];
                    smi++;
                }
            }
            /* check:
            printf("\nsmall%d_%d: ");
            for (int k = 0; k < 9; k++){
             printf("%d ", small33[k]);
            }*/

            // 2. check dupNum in small33?
            dupNum = DupNumInArr(small33, count, 9);
            // 3. if dupNum != 0, print
            if (dupNum != 0) {
                for (int i_ = i; i_ < i + 3; i_++) {
                    for (int j_ = j; j_ < j + 3; j_++) {
                        if (s[i_][j_] == dupNum) {
                            printf("%d %d\n", i_, j_);
                        }
                    }
                }
                return 1;
            }

        } // in each 3*3 small space 
    }// in 3*3


    // 4. if pass 234, print 0
    printf("0\n");

    return 0;
}


int DupNumInArr(int* a, int* count, int length)
{
    // input: get an array | output: if has duplnum, return num, else return 0
    // 1. confirm count arr initailized
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    // 2. count arr
    for (int i = 0; i < length; i++) {
        count[(a[i])]++;
    }
    // 3. if count[1-9] someone >1, return that i (dupNum), else rt 0
    for (int i = 1; i < 10; i++) {
        if (count[i] > 1) {
            return i;
        }
    }
    return 0;
}