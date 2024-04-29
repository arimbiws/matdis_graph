#include <stdio.h>

struct sisi {
    int asal;
    int tujuan;
    int berat;
};

struct sisi edges[] = {
    {0, 1, 10},
    {0, 3, 15},
    {1, 2, 20},
    {1, 4, 13},
    {2, 5, 12},
    {3, 4, 11},
    {3, 5, 16},
    {4, 2, 5},
    {4, 5, 21}
};

int dikunjungi[9];
int bobotMST = 0;

void printGraph() {
    printf("Graf:\n");
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        printf("(sisi %d - %d) \tbobot : %d\n", edges[i].asal, edges[i].tujuan, edges[i].berat);
    }
    printf("\n ===== Hasil =====\n");
    printf("Total MST: %d\n", bobotMST);
}

// Fungsi untuk mencari sisi terkecil yang menghubungkan simpul dalam MST
void cariSisiTerkecil(int *v, int *vn) {
    int min = 999;
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        if ((dikunjungi[edges[i].asal] && !dikunjungi[edges[i].tujuan]) ||
            (!dikunjungi[edges[i].asal] && dikunjungi[edges[i].tujuan])) {
            if (edges[i].berat < min) {
                min = edges[i].berat;
                *v = edges[i].asal;
                *vn = edges[i].tujuan;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 6; i++) {
        dikunjungi[i] = 0;
    }

    printGraph();

    dikunjungi[0] = 1;
    int k = 1;

    while (k < 6) {
        int v, vn;
        cariSisiTerkecil(&v, &vn);
        printf("%d - %d, Bobot: %d\n", v, vn, edges[vn].berat);
        bobotMST += edges[vn].berat;
        dikunjungi[vn] = 1;
        k++;
    }

    printf("\nBobot MST tersebut sebesar : %d\n", bobotMST);
    return 0;
}