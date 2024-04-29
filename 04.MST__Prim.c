#include <stdio.h>

// Representasi matriks bobot graf
int graf[6][6] = {{0, 10, 0, 30, 45, 0},
                   {10, 0, 50, 0, 40, 25},
                   {0, 50, 0, 0, 35, 15},
                   {30, 0, 0, 0, 0, 20},
                   {45, 40, 35, 0, 0, 55},
                   {0, 25, 15, 20, 55, 0}};

// Representasi array edge dengan dua baris, masing-masing untuk vertex awal dan akhir
int sisi[2][10] = {{0, 2, 3, 1, 0, 2, 1, 0, 1, 4}, 
                    {1, 5, 5, 5, 3, 4, 4, 4, 3, 5}};

// Representasi matriks MST dengan default nilai nol
int MST[6][6] = {{0}};

// Jumlah edge yang akan diproses
int jumlah_sisi = sizeof(sisi[0]) / sizeof(sisi[0][0]);

// Inisialisasi variabel counter edge dan total bobot MST
int hitung_sisi = 1, total_bobot = 0;

void resetArray(int arr[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        arr[i] = 0;
    }
}

int main() {
    // Array untuk tracking vertex yang telah dikunjungi
    int dikunjungi[6] = {0};

    for (int sisi_ke = 0; sisi_ke < jumlah_sisi && hitung_sisi <= 5; sisi_ke++) {
        int vertex_awal = sisi[0][sisi_ke], vertex_akhir = sisi[1][sisi_ke];

        resetArray(dikunjungi, 6);

        // Copy nilai dari MST ke dikunjungi untuk vertex awal
        for (int j = 0; j < 6; j++) {
            dikunjungi[j] = MST[vertex_awal][j];
        }

        int cek = 0;
        while (cek < 6) {
            for (int j = 0; j < 6; j++) {
                if (dikunjungi[j] == 1 && MST[j][j] == 0) {
                    dikunjungi[j] = 1;
                    for (int k = 0; k < 6; k++) {
                        if (MST[j][k] == 1) {
                            dikunjungi[k] = 1;
                        }
                    }
                }
            }
            cek++;
        }

        if (dikunjungi[vertex_akhir] == 0) {
            MST[vertex_awal][vertex_akhir] = 1;
            MST[vertex_akhir][vertex_awal] = 1;
            total_bobot += graf[vertex_awal][vertex_akhir];

            printf("\n%d - %d bobot %d total MST = %d", vertex_awal, vertex_akhir, graf[vertex_awal][vertex_akhir], total_bobot);

            graf[vertex_awal][vertex_akhir] = 0;
            graf[vertex_akhir][vertex_awal] = 0;
            hitung_sisi++;
        }
    }

    return 0;
}
