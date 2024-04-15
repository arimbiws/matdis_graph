#include <stdio.h>
#include <stdlib.h>

void pruferCode_reduce_tree(int tree[], int n) {
    int pruferCode[n - 2];
    int degrees[n];
    int is_removed[n];
    for (int i = 0; i < n; i++) {
        degrees[i] = 1;
        is_removed[i] = 0;
    }

    for (int i = 0; i < n - 2; i++) {
        degrees[tree[i]]++;
    }

    int j = 0;
    for (int i = 0; i < n - 2; i++) {
        int min_daun;
        for (int k = 0; k < n; k++) {
            if (degrees[k] == 1 && !is_removed[k]) {
                min_daun = k;
                break;
            }
        }

        int induk = tree[j++];
        pruferCode[i] = induk;
        degrees[induk]--;
        degrees[min_daun]--;
        is_removed[min_daun] = 1;

        printf("Langkah %d: Hapus simpul %d\n", i + 1, min_daun + 1);
    }

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

    printf("\nPrufer Code: ");
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", pruferCode[i]);
    }
    printf("\n");
    printf("Edge yang Dikurangi: (%d, %d)\n", daun1 -1 , daun2 +1);
    printf("\nRekonstruksi Kembali:\n");
    for (int i = 0; i < n - 2; i++) {
        printf("Edge %d: %d ---- %d\n", i + 1, pruferCode[i], daun1);
        daun1 = pruferCode[i];
    }
}

void pruferCode_from_vertices(int n) {
    int vertex1, vertex2;
    printf("Masukkan dua vertex yang terhubung (dari 1 hingga %d): ", n);
    scanf("%d %d", &vertex1, &vertex2);

    printf("Prufer Code: ");
    for (int i = 1; i <= n; i++) {
        if (i != vertex1 && i != vertex2) {
            printf("%d ", i);
        }
    }
    printf("\n");
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

    pruferCode_from_vertices(n);

    return 0;
}