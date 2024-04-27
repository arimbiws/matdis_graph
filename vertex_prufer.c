//1 arimbi
#include <stdio.h>
#include <stdlib.h>

int* getPruferCode(int n, int** edges, int m) {
    int* degree = calloc(n + 2, sizeof(int));
    for (int i = 0; i < m; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    int* pruferCode = malloc((n - 2) * sizeof(int));
    int j = 0;

    for (int k = 0; k < n - 2; k++) {
        int leaf = 0;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1 && (leaf == 0 || i < leaf)) {
                leaf = i;
            }
        }
//2 there
        int u = (edges[j][0] == leaf) ? edges[j][1] : edges[j][0];
        j++;
        degree[u]--;
        pruferCode[k] = u;
    }

    free(degree);
    return pruferCode;
}

int main() {
    int n, m;
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &n);

    printf("Masukkan jumlah edge: ");
    scanf("%d", &m);

    if (n - 1 != m) {
        printf("Jumlah edge harus sama dengan jumlah vertex minus satu.\n");
        return 1;
    }
// 3 mahda
    int** edges = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        edges[i] = malloc(2 * sizeof(int));
        printf("Masukkan edge %d: ", i + 1);
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int* pruferCode = getPruferCode(n, edges, m);
    printf("Prufer Code: ");
    for (int i = 0; i < n - 2; i++) {
        printf("%d ", pruferCode[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        free(edges[i]);
    }
    free(edges);
    free(pruferCode);

    return 0;
}
