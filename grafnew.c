#include <stdio.h>
#include <stdlib.h>

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

    // Menghitung derajat vertex
    int vertex_degrees[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        vertex_degrees[i] = 0;
        for (int j = 0; j < num_nodes; j++) {
            vertex_degrees[i] += adj_matrix[i][j];
        }
    }

    // Mengecek konektivitas graf
    int is_connected = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (vertex_degrees[i] > 0) {
            is_connected = 1;
            break;
        }
    }

    // Mencetak informasi graf
    printf("\n");
    printf("===================== \n");
    printf("   Matriks adjacency \n");
    printf("===================== \n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nInformasi Graf:\n");
    printf("\n");
    printf("Jumlah vertex: %d\n", num_nodes);
    printf("Terhubung: %s\n", is_connected ? "Ya" : "Tidak");

    for (int i = 0; i < num_nodes; i++) {
        printf("Derajat vertex %d: %d\n", i + 1, vertex_degrees[i]);
    }

    return 0;
}
