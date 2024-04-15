#include <stdio.h>
#include <stdlib.h>

void pruferCode_reduce_tree(int tree[], int n) {
    int pruferCode[n - 2];
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
        int min_daun;
        for (int k = 0; k < n; k++) {
            if (degrees[k] == 1) {
                min_daun = k;
                break;
            }
        }

        // Temukan simpul yang terhubung dengan simpul tersebut
        int induk = tree[j++];
        pruferCode[i] = induk;

        // Kurangi derajat simpul yang terhubung
        degrees[induk]--;
        degrees[min_daun]--;

        // Tampilkan simpul yang dihapus
        printf("Langkah %d: Hapus simpul %d\n", i + 1, min_daun + 1);
    }

    // Sisa dua simpul adalah simpul yang tidak terdapat dalam kode Prufer
    int daun1, daun2;
    for (int i = 0; i < n; i++) {
        if (degrees[i] == 1) {
            if (daun1 == 0) {
                daun1 = i;
            } else {
                daun2 = i;
                break;
            }
        }
    }

    // Tampilkan hasil
    printf("\nPrufer Code: ");
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", pruferCode[i]);
    }
    printf("\n");
    printf("Edge yang Dikurangi: (%d, %d)\n", daun1, daun2 + 1);
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

    pruferCode_reduce_tree(tree, n);

    return 0;
}
