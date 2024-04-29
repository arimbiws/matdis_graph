#include <stdio.h>

#define V 6
#define E 9

struct Edge {
    int asal; 
    int tujuan; 
    int berat;
};

void printGraph(struct Edge edges[]) {
    printf("Graf:\n");
    for (int i = 0; i < E; i++) {
        printf("(%d) %d - %d : %d\n", i+1, edges[i].asal, edges[i].tujuan, edges[i].berat);
    }
}
int cari(int induk[], int i) {
    if (induk[i] == -1)
        return i;
    return cari(induk, induk[i]);
}


void gabungan(int induk[], int x, int y) {
    int xset = cari(induk, x);
    int yset = cari(induk, y);
    induk[xset] = yset;
}

void KruskalMST(struct Edge edges[]) {
    int induk[V];
    for (int i = 0; i < V; i++)
        induk[i] = -1;

    int edgeCount = 0;
    int beratMST = 0;
    while (edgeCount < V - 1) {
        int min = 9999, minIndex = -1;
        for (int i = 0; i < E; i++) {
            if (cari(induk, edges[i].asal) != cari(induk, edges[i].tujuan) && edges[i].berat < min) {
                min = edges[i].berat;
                minIndex = i;
            }
        }

        gabungan(induk, edges[minIndex].asal, edges[minIndex].tujuan);
        printf("%d - %d\n", edges[minIndex].asal, edges[minIndex].tujuan);
        beratMST += min;
        edgeCount++;
    }
    printf("Bobot MST: %d\n", beratMST);
}

int main() {
    struct Edge edges[] = {
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
     printGraph(edges);
    KruskalMST(edges);

return 0;
}