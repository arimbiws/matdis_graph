#include <stdio.h>
#include <stdlib.h>

// 3
void DFS(int vertex, int nomorNodes, int matriksAdjacency[nomorNodes][nomorNodes], int pengunjung[nomorNodes]) { 
    pengunjung[vertex] = 1;
    
    for (int i = 0; i < nomorNodes; i++) {
        if (matriksAdjacency[vertex][i] && !pengunjung[i]) {
            DFS(i, nomorNodes, matriksAdjacency, pengunjung);
        }
    }
}
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
        printf("    bentuk matriks \n");
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

// pengurutan menggunakan bubble sort
int temp = 0;
for (int i = 1; i<= nomorNodes ; i++){
    for (int j = i+1 ; j<=nomorNodes; j++){
        if (derajatVertex[i]<derajatVertex[j]){
            temp = derajatVertex [i];
            derajatVertex[i]=derajatVertex[j];
            derajatVertex [i]=temp;
            derajatVertex[i]=j;
            derajatVertex[j]=i;
        }
    }
}

printf("tampilan vertex sesuai derajat");
for (int i = 0; i < nomorNodes; i++) {
    printf("Derajat vertex ke %d adalah %d\n", derajatVertex[i] + 1, derajatVertex[i]);
}


// Assume w[] and T[] are declared as global arrays
int w[nomorNodes];
int T[nomorNodes];

// Initialize arrays w[] and T[]
for (int i = 0; i < nomorNodes; i++) {
    w[i] = 0;
    T[i] = 0;
}

// Assign colors to vertices based on their degree
int warna = 1;
w[derajatVertex[0]] = warna; // Assign color to the vertex with highest degree
int total = 1;

// Initialize T[] array with the neighbors of the highest degree vertex
for (int i = 0; i < nomorNodes; i++) {
    T[i] = matriksAdjacency[derajatVertex[0]][i];
}
while (total < nomorNodes) {
    for (int i = 0; i < nomorNodes; i++) {
        if (w[derajatVertex[i]] == 0 && T[derajatVertex[i]] == 0) {
            w[derajatVertex[i]] = warna;
            total++;
            for (int j = 0; j < nomorNodes; j++) {
                if (T[j] == 0) {
                    T[j] = matriksAdjacency[derajatVertex[i]][j];
                }
            }
        }
    }
    warna++;
    for (int j = 0; j < nomorNodes; j++) {
        T[j] = 0;
    }
}

// Print the colors assigned to each vertex
for (int i = 0; i < nomorNodes; i++) {
    printf("Warna vertex ke %d adalah %d\n", i + 1, w[i]);
}
return 0;
}