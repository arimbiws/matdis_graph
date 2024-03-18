#include <stdio.h>
#include <stdlib.h>

// 1
int main() {
    int nomorNodes;
        printf("Masukkan jumlah vertex: ");
        scanf("%d", &nomorNodes);
        printf("\n");

    int matriksAdjacency[nomorNodes][nomorNodes]; 
    for (int i = 0; i < nomorNodes; i++) {
        for (int j = 0; j < nomorNodes; j++) {
            matriksAdjacency[i][j] = 0;
        }
    }
// 2
    for (int i = 0; i < nomorNodes; i++) {
        for (int j = 0; j < nomorNodes; j++) {
            int penghubung;
            printf("Apakah ada edge dari %d ke %d (1/0): ", i + 1, j + 1);
            scanf("%d", &penghubung);
            if (penghubung) {
                matriksAdjacency[i][j] = 1;
            }
        }
    }

// 3
void DFS(int vertex, int nomorNodes, int matriksAdjacency[nomorNodes][nomorNodes], int pengunjung[nomorNodes]) { 
    pengunjung[vertex] = 1;
    
    for (int i = 0; i < nomorNodes; i++) {
        if (matriksAdjacency[vertex][i] && !pengunjung[i]) {
            DFS(i, nomorNodes, matriksAdjacency, pengunjung);
        }
    }
}
// 4
int pengunjung[nomorNodes];
    for (int i = 0; i < nomorNodes; i++) {
        pengunjung[i] = 0;
    }

int penghubung = 0;
    for (int i = 0; i < nomorNodes; i++) {
        if (!pengunjung[i]) {
            DFS(i, nomorNodes, matriksAdjacency, pengunjung);
            penghubung++;
        }
    }
 
 // 5
    printf("\n");
     printf("===================== \n");
     printf("   Matriks adjacency \n");
    printf("===================== \n");

    for (int i = 0; i < nomorNodes; i++) {
        for (int j = 0; j < nomorNodes; j++) {
            printf("%d ", matriksAdjacency[i][j]);
        }
        printf("\n");
    }
    printf("\nInformasi Graf:\n");
    printf("\n");
    printf("Jumlah vertex: %d\n", nomorNodes);
    printf("Terhubung: %s\n", penghubung == 1 ? "Ya" : "Tidak"); 
//6.
    int derajatVertex[nomorNodes];
    for (int i = 0; i < nomorNodes; i++) {
        derajatVertex[i] = 0;
        for (int j = 0; j < nomorNodes; j++) {
            derajatVertex[i] += matriksAdjacency[i][j];
        }
    }

    for (int i = 0; i < nomorNodes; i++) {
        printf("Derajat vertex %d: %d\n", i + 1, derajatVertex[i]);
    }
return 0;
}
