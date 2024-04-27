#include <stdio.h>
#include <stdlib.h>

int M[6][6] = {
    {0, 10, 0, 30, 45, 0},
    {10, 0, 50, 0, 40, 25},
    {0, 50, 0, 0, 35, 15},
    {30, 0, 0, 0, 0, 20},
    {45, 40, 35, 0, 0, 55},
    {0, 52, 15, 20, 55, 0}
};
int T[6];
int p, v, vn, k, m, mst;

int main() {
    for (int i = 0; i < 6; i++) {
        T[i] = 0;
    }
    T[0] = 1;
    k = 1;
    while (k <= 5) {
        m = 99;
        p = 0;
        while (p <= 5) {
            if (T[p] == 1) {
                for (int i = 0; i <= 5; i++) {
                    if ((M[p][i] < m) && (M[p][i] != 0) && (T[i] != 1) && (p != i)) {
                        m = M[p][i];
                        v = p;
                        vn = i;
                    }
                }
            }
            p++;
        }
        printf("%d - %d\n", v, vn);
        mst = mst + m;
        T[vn] = 1;
        k++;
    }
    printf("MST weight: %d\n", mst);
    return 0;
}
