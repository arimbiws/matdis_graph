#include <stdio.h>
#include <stdbool.h>



#define V 6
#define E 9

struct Sisi {
    int asal;
    int tujuan;
    int berat;
};

struct Sisi edges[E] = {
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

int dikunjungi[V];
int bobotMST = 0;

// 2

int cariSimpulDenganBobotMin(int bobot[], bool dalamMST[]) {
    int min = 999;
    int indeksMin = -1;

    for (int v = 0; v < V; v++) {
        if (dalamMST[v] == false && bobot[v] < min) {
            min = bobot[v];
            indeksMin = v;
        }
    }
    return indeksMin;
}
void bangunMST() {
    int parent[V];
    int bobot[V];
    bool dalamMST[V];
    for (int i = 0; i < V; i++) {
        bobot[i] = 999;
        dalamMST[i] = false;
    }
    bobot[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = cariSimpulDenganBobotMin(bobot, dalamMST);
        dalamMST[u] = true;

// 3

        for (int v = 0; v < E; v++) {
            if ((edges[v].asal == u || edges[v].tujuan == u) 
            && dalamMST[edges[v].tujuan] == false 
            && edges[v].berat < bobot[edges[v].tujuan]) {
                parent[edges[v].tujuan] = u;
                bobot[edges[v].tujuan] = edges[v].berat;
            }
        }
    }

    for (int i = 1; i < V; i++) {
        printf("%d - %d, Bobot: %d\n", parent[i], i, bobot[i]);
        bobotMST += bobot[i];
    }
}

void printGraph() {
    printf("Graf:\n");
    for (int i = 0; i < E; i++) {
        printf("(sisi %d - %d) \tbobot : %d\n", edges[i].asal, edges[i].tujuan, edges[i].berat);
    }
    printf("\n===== Hasil =====\n");

    bangunMST();
}

// 1 

int main() {
    for (int i = 0; i < V; i++) {
        dikunjungi[i] = 0;
    }

    printGraph();

    printf("\nBobot MST tersebut sebesar : %d\n", bobotMST);
    return 0;
}