#include <stdio.h>

struct sisi {
    int asal;
    int tujuan;
    int berat;
};

struct sisi edges[] = {
    {0, 1, 10},
    {0, 3, 30},
    {0, 4, 45},
    {1, 2, 50},
    {1, 5, 25},
    {2, 4, 35},
    {2, 5, 15},
    {3, 5, 20},
    {4, 5, 55}
};

int dikunjungi[6];
int bobotMST = 0;

void printGraph() {
    printf("Graf:\n");
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        printf("(sisi %d = %d - %d) bobot : %d\n", i+1, edges[i].asal, edges[i].tujuan, edges[i].berat);
    }
    printf("\n ===== Hasil =====\n");
}

// Fungsi untuk mencari sisi terkecil yang menghubungkan simpul dalam MST
void cariSisiTerkecil(int *v, int *vn) {
    int min = 999;
    for (int i = 0; i < 6; i++) {
        if (dikunjungi[i]) {
            for (int j = 0; j < sizeof(edges) / sizeof(edges[0]); j++) {
                if (!dikunjungi[edges[j].tujuan] && edges[j].berat < min) {
                    min = edges[j].berat;
                    *v = edges[j].asal;
                    *vn = edges[j].tujuan;
                }
            }
        }
    }
}

// Fungsi untuk membangun Minimum Spanning Tree
void bangunMST() {
    dikunjungi[0] = 1;
    int k = 1;

    while (k < 6) {
        int v, vn;
        cariSisiTerkecil(&v, &vn);
        printf("%d - %d\n", v, vn);
        bobotMST += edges[vn].berat;
        dikunjungi[vn] = 1;
        k++;
    }
}

int main() {
    for (int i = 0; i < 6; i++) {
        dikunjungi[i] = 0;
    }
    printGraph();
    bangunMST();

    printf("\nBobot MST tersebut sebesar : %d\n", bobotMST);
    return 0;
}
