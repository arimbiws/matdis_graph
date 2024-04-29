#include <stdio.h>
#include <stdlib.h>

// Inisialisasi graf berbobot
int graf[6][6] = {
    {0, 10, 0, 30, 45, 0},
    {10, 0, 50, 0, 40, 25},
    {0, 50, 0, 0, 35, 15},
    {30, 0, 0, 0, 0, 20},
    {45, 40, 35, 0, 0, 55},
    {0, 52, 15, 20, 55, 0}
};

int dikunjungi[6];
int bobotMST = 0;

// Fungsi untuk mencari sisi terkecil yang menghubungkan simpul dalam MST
void cariSisiTerkecil(int *v, int *vn) {
    int min = 999;
    for (int i = 0; i < 6; i++) {
        if (dikunjungi[i]) {
            for (int j = 0; j < 6; j++) {
                if (!dikunjungi[j] && graf[i][j] != 0 && graf[i][j] < min) {
                    min = graf[i][j];
                    *v = i;
                    *vn = j;
                }
            }
        }
    }
}

// Fungsi untuk membangun Minimum Spanning Tree
void bangunMST() {
    dikunjungi[0] = 1;
    int k = 1;

    while (k <= 5) {
        int m, v, vn;
        cariSisiTerkecil(&v, &vn);
        printf("%d - %d\n", v, vn);
        bobotMST += graf[v][vn];
        dikunjungi[vn] = 1;
        k++;
    }
}

int main() {
    for (int i = 0; i < 6; i++) {
        dikunjungi[i] = 0;
    }

    bangunMST();

    printf("Bobot MST tersebut sebesar : %d\n", bobotMST);
    return 0;
}
