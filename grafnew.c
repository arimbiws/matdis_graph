#include <stdio.h>

int main() {
    printf("Program matrik ketetanggaan\n");
    printf("===========================\n");
    
    int a[7][7];
    int hm[7] = {0, 0, 0, 0, 0, 0, 0};
    int T[7] = {0, 0, 0, 0, 0, 0, 0};
    int baris;

    printf("input jumlah vertex: ");
    scanf("%d", &baris);

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris; j++) {
            printf("jika vertek %d dan vertek ke %d terhubung, tulis 1\n", 
i+1, j+1);
	    printf("jika tidak, tulis 0: \n");
            scanf("%d", &a[i][j]);
        }
    }

    // mengisi array hm dengan vertex yang terhubung ke vertex 1
    for (int i = 1; i < baris; i++) {
        hm[i] = a[0][i];
    }

    // perubahan nilai hm
    for (int i = 1; i < baris; i++) {
        for (int j = 1; j < baris; j++) {
            if (hm[j] == 1 && T[j] == 0) {
                T[j] = 1;
                for (int k = 1; k < baris; k++) {
                    if (a[j][k] == 1 && hm[k] == 0) {
                        // Lakukan tindakan yang sesuai di sini
                    }
                }
            }
        }
    }

    printf("Matriks Ketetanggaan:\n");
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
