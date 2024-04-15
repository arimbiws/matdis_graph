#include <stdio.h>
#include <stdlib.h>

void prufer_code_reduce_tree(int tree[], int n) {
    int prufer_code[n - 2];
    int degrees[n];

    // Inisialisasi derajat setiap simpul menjadi 1
    for (int i = 0; i < n; i++) {
        degrees[i] = 1;
    }

    // Hitung derajat setiap simpul
    for (int i = 0; i < n - 2; i++) {
        degrees[tree[i]]++;
    }

    int j = 0;
    for (int i = 0; i < n - 2; i++) {
        // Cari simpul dengan derajat keluar 1 terkecil
        int min_leaf;
        for (int k = 0; k < n; k++) {
            if (degrees[k] == 1) {
                min_leaf = k;
                break;
            }
        }

        // Temukan simpul yang terhubung dengan simpul tersebut
        int parent = tree[j++];
        prufer_code[i] = parent;

        // Kurangi derajat simpul yang terhubung
        degrees[parent]--;
        degrees[min_leaf]--;

        // Tampilkan simpul yang dihapus
        printf("Langkah %d: Hapus simpul %d\n", i + 1, min_leaf);
    }

    // Sisa dua simpul adalah simpul yang tidak terdapat dalam kode Prufer
    int leaf1, leaf2;
    for (int i = 0; i < n; i++) {
        if (degrees[i] == 1) {
            if (leaf1 == 0) {
                leaf1 = i;
            } else {
                leaf2 = i;
                break;
            }
        }
    }

    // Tampilkan hasil
    printf("\nPrufer Code: ");
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", prufer_code[i]);
    }
    printf("\n");
    printf("Edge yang Dikurangi: (%d, %d)\n", leaf1, leaf2);
}

int main() {
    int n;
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &n);

    int tree[n - 2];
    printf("Masukkan simpul-simpul yang terhubung:\n");
    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &tree[i]);
    }

    prufer_code_reduce_tree(tree, n);

    return 0;
}
