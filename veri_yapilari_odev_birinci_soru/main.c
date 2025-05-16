#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 500

// Ekleme Sıralama (Insertion Sort) fonksiyonu
void eklemeSirala(int dizi[], int n) {
    for (int i = 1; i < n; i++) {
        int anahtar = dizi[i];
        int j = i - 1;
        while (j >= 0 && dizi[j] > anahtar) {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = anahtar;
    }
}

// Seçme Sıralama (Selection Sort) fonksiyonu
void secmeSirala(int dizi[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_indeks = i;
        for (int j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[min_indeks])
                min_indeks = j;
        }
        int gecici = dizi[min_indeks];
        dizi[min_indeks] = dizi[i];
        dizi[i] = gecici;
    }
}

// Diziyi kopyalayan fonksiyon
void diziKopyala(int kaynak[], int hedef[], int n) {
    for (int i = 0; i < n; i++)
        hedef[i] = kaynak[i];
}

int main() {
    int orijinal[BOYUT];
    int dizi1[BOYUT], dizi2[BOYUT];

    // Rastgele sayı üretimi için başlatma
    srand(time(NULL));
    for (int i = 0; i < BOYUT; i++)
        orijinal[i] = rand() % 1001; // 0-1000 arası rastgele sayılar

    diziKopyala(orijinal, dizi1, BOYUT);
    diziKopyala(orijinal, dizi2, BOYUT);

    clock_t basla, bitir;
    double sure;

    // Ekleme sıralama süresi ölçümü
    basla = clock();
    eklemeSirala(dizi1, BOYUT);
    bitir = clock();
    sure = ((double)(bitir - basla)) / CLOCKS_PER_SEC;
    printf("Ekleme Sıralama süresi: %f saniye\n", sure);

    // Seçme sıralama süresi ölçümü
    basla = clock();
    secmeSirala(dizi2, BOYUT);
    bitir = clock();
    sure = ((double)(bitir - basla)) / CLOCKS_PER_SEC;
    printf("Seçme Sıralama süresi: %f saniye\n", sure);

    return 0;
}
