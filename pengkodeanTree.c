#include <stdio.h>
#include <stdlib.h>

void pruferCode_reduce_tree(int tree[], int n) {
    int pruferCode[n - 2];
    int degrees[n];
    int is_removed[n]; // Tambahkan array untuk melacak simpul yang dihapus

    // Inisialisasi derajat setiap simpul menjadi 1 dan is_removed menjadi 0
    for (int i = 0; i < n; i++) {
        degrees[i] = 1;
        is_removed[i] = 0;
    }

    // Hitung derajat setiap simpul
    for (int i = 0; i < n - 2; i++) {
        degrees[tree[i]]++;
    }

    int j = 0;
    for (int i = 0; i < n - 2; i++) {
        // Cari simpul dengan derajat keluar 1 terkecil yang belum dihapus (simpul daun)
        int min_daun;
        for (int k = 0; k < n; k++) {
            if (degrees[k] == 1 && !is_removed[k]) { // Perhatikan penambahan kondisi !is_removed[k]
                min_daun = k;
                break;
            }
        }

        // Temukan simpul yang terhubung dengan simpul tersebut (simpul induk)
        int induk = tree[j++];
        pruferCode[i] = induk;

        // Kurangi derajat simpul yang terhubung dan tandai simpul yang telah dihubungkan sebagai sudah dihapus
        degrees[induk]--;
        degrees[min_daun]--;
        is_removed[min_daun] = 1;

        // Tampilkan simpul yang dihapus
        printf("Langkah %d: Hapus simpul %d\n", i + 1, min_daun + 1);
    }

    // Sisa dua simpul adalah simpul yang tidak terdapat dalam kode Prufer
    int daun1, daun2;
    for (int i = 0; i < n; i++) {
        if (!is_removed[i]) {
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
    printf("Edge yang Dikurangi: (%d, %d)\n", daun1   , daun2 + 1); // Tambahkan +1 karena indeks dimulai dari 0

    // Rekonstruksi kembali ke pohon
    printf("\nRekonstruksi Kembali:\n");
    for (int i = 0; i < n - 2; i++) {
        printf("Edge %d: %d ---- %d\n", i + 1, pruferCode[i], daun1);
        daun1 = pruferCode[i];
    }
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
