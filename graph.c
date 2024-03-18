#include <stdio.h>
#include <stdlib.h>
/*
perubahan 
num_nodes = nomorNodes
adj_matrix = matriksAdjacency
visited = mengunjungi
*/


// 1
int main() {

    int num_nodes;

    // Mendapatkan jumlah vertex dari user
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &num_nodes);
    printf("\n");

    // Deklarasi matriks adjacency
    int adj_matrix[num_nodes][num_nodes]; 
    // Inisialisasi matriks adjacency
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            adj_matrix[i][j] = 0;
        }
    }
//2
    // Input edge dari user
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            int is_connected;
            printf("Apakah ada edge dari %d ke %d (1/0): ", i + 1, j + 1);
            scanf("%d", &is_connected);
            if (is_connected) {
                adj_matrix[i][j] = 1;
            }
        }
    }

// 3
// Fungsi untuk melakukan pencarian kedalaman terlebih dahulu (depth-first search)
void DFS(int vertex, int num_nodes, int adj_matrix[num_nodes][num_nodes], int visited[num_nodes]) {
    visited[vertex] = 1; // Menandai vertex yang sedang dikunjungi
    for (int i = 0; i < num_nodes; i++) {
        if (adj_matrix[vertex][i] && !visited[i]) { // Jika ada edge dan vertex belum dikunjungi
            DFS(i, num_nodes, adj_matrix, visited); // Lakukan pencarian kedalaman terlebih dahulu dari vertex i
        }
    }
}
// 4
    // Mengecek konektivitas graf menggunakan DFS
    int visited[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0; // Menandai semua vertex belum dikunjungi
    }

    int is_connected = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) { // Jika vertex belum dikunjungi
            DFS(i, num_nodes, adj_matrix, visited); // Lakukan pencarian kedalaman terlebih dahulu dari vertex i
            is_connected++; // Menambah jumlah komponen terhubung
        }
    }
 
 // 5
    // Mencetak informasi graf
    printf("\n");
    printf("===================== \n");
    printf("   Matriks adjacency \n");
    printf("===================== \n");

    //cetak matriks
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nInformasi Graf:\n");
    printf("\n");
    printf("Jumlah vertex: %d\n", num_nodes);
    printf("Terhubung: %s\n", is_connected == 1 ? "Ya" : "Tidak"); // Jika jumlah komponen terhubung hanya 1, maka graf terhubung

//6.
    // Menghitung derajat vertex
    int vertex_degrees[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        vertex_degrees[i] = 0;
        for (int j = 0; j < num_nodes; j++) {
            vertex_degrees[i] += adj_matrix[i][j];
        }
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Derajat vertex %d: %d\n", i + 1, vertex_degrees[i]);
    }

    return 0;
}
