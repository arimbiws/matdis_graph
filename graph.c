#include <stdio.h>
#include <stdlib.h>

//1
void DFS(int vertex, int nomorNodes, int matriksAdjacency[nomorNodes][nomorNodes], int pengunjung[nomorNodes]) { 
    pengunjung[vertex] = 1;
    
    for (int i = 0; i < nomorNodes; i++) {
        if (matriksAdjacency[vertex][i] && !pengunjung[i]) {
            DFS(i, nomorNodes, matriksAdjacency, pengunjung);
        }
    }
}

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
//2
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

    int pengunjung[nomorNodes];
    for (int i = 0; i < nomorNodes; i++) {
        pengunjung[i] = 0;
    }
//3
    int penghubung = 0;
    for (int i = 0; i < nomorNodes; i++) {
        if (!pengunjung[i]) {
            DFS(i, nomorNodes, matriksAdjacency, pengunjung);
            penghubung++;
        }
    }

    printf("\n");
    printf("===================== \n");
    printf("    bentuk matriks \n");
    printf("===================== \n");

    for (int i = 0; i < nomorNodes; i++) {
        for (int j = 0; j < nomorNodes; j++) {
            printf("%d ", matriksAdjacency[i][j]);
        }
        printf("\n");
    }
//4
    printf("\nInformasi Graf:\n");
    printf("\n");
    printf("Jumlah vertex: %d\n", nomorNodes);
    printf("Terhubung: %s\n", penghubung == 1 ? "Ya" : "Tidak"); 

    int derajatVertex[nomorNodes];
    for (int i = 0; i < nomorNodes; i++) {
        derajatVertex[i] = 0;
        for (int j = 0; j < nomorNodes; j++) {
            derajatVertex[i] += matriksAdjacency[i][j];
        }
    }
//5
    // Pengurutan derajat vertex dengan Bubble Sort
    for (int i = 0; i < nomorNodes-1; i++) {
        for (int j = 0; j < nomorNodes-i-1; j++) {
            if (derajatVertex[j] < derajatVertex[j+1]) {
                int temp = derajatVertex[j];
                derajatVertex[j] = derajatVertex[j+1];
                derajatVertex[j+1] = temp;
            }
        }
    }

    printf("Tampilan vertex sesuai derajat:\n");
    for (int i = 0; i < nomorNodes; i++) {
        printf("Derajat vertex ke %d adalah %d\n", i + 1, derajatVertex[i]);
    }
//6
    // Algoritma pendekatan Greedy
    int warna[nomorNodes];
    for (int i = 0; i < nomorNodes; i++) {
        warna[i] = 0;
    }

    for (int i = 0; i < nomorNodes; i++) {
        int vertex = i;
        if (warna[vertex] == 0) {
            int j = 1;
            while (1) {
                int cekWarna = 1;
                for (int k = 0; k < nomorNodes; k++) {
                    if (matriksAdjacency[vertex][k] && warna[k] == j) {
                        cekWarna = 0;
                        break;
                    }
                }
                if (cekWarna) {
                    warna[vertex] = j;
                    break;
                }
                j++;
            }
        }
    }

    printf("Warna yang diberikan untuk setiap vertex:\n");
    for (int i = 0; i < nomorNodes; i++) {
        printf("Warna vertex ke %d adalah %d\n", i + 1, warna[i]);
    }

    return 0;
}