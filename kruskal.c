#include <stdio.h>
#define V 6
#define E 9

struct sisi {
    int asal; 
    int tujuan; 
    int berat;
};
// 2
void printGraph(struct sisi tepi[]) {
    printf("Graf:\n");
    for (int i = 0; i < E; i++) {
        printf("(sisi %d = %d - %d) bobot : %d\n", i+1, tepi[i].asal, tepi[i].tujuan, tepi[i].berat);
    }
    printf("\n ===== Hasil =====");
}

int cari(int induk[], int i) {
    if (induk[i] == -1)
        return i;
    return cari(induk, induk[i]);
}
// 3
void gabungan(int induk[], int x, int y) {
    int xset = cari(induk, x);
    int yset = cari(induk, y);
    induk[xset] = yset;
}

void KruskalMST(struct sisi tepi[]) {
    int induk[V];
    for (int i = 0; i < V; i++)
        induk[i] = -1;
    int sisiCount = 0;
    int beratMST = 0;
// 4
    while (sisiCount < V - 1) {
        int terkecil = 9999, Indeksterkecil = -1;
        for (int i = 0; i < E; i++) {
            if (cari(induk, tepi[i].asal) != cari(induk, tepi[i].tujuan) && tepi[i].berat < terkecil) {
                terkecil = tepi[i].berat;
                Indeksterkecil = i;
            }
        }

        gabungan(induk, tepi[Indeksterkecil].asal, tepi[Indeksterkecil].tujuan);
        beratMST += terkecil;
        printf("\n");
        printf("%d - %d \tbobot : %d, ", tepi[Indeksterkecil].asal, tepi[Indeksterkecil].tujuan, tepi[Indeksterkecil].berat);
        printf("total MST: %d", beratMST);
        sisiCount++;
    }
    printf("\n\n===== Total =====");
    printf("\nTotal bobot MST: %d\n", beratMST);
}
// 1
int main() {
    struct sisi tepi[] = {
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
    printGraph(tepi);
    KruskalMST(tepi);

    return 0;
}
