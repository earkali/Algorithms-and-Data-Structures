#include <stdio.h>
#include <stdlib.h>

struct urun {
    int id;
    char isim[20];
    float fiyat;
    int stok;
};

void urunEkle();
void urunGuncelle();
void urunGoster();
void urunSil();
int menu();

int main(void) {
    menu();
    return 0;
}

int menu() {
    int secim;
    while (1) {
        printf("\n-----MENU-----\n");
        printf("1. Urun ekle\n");
        printf("2. Urun guncelle\n");
        printf("3. Urun goster\n");
        printf("4. Urun sil\n");
        printf("5. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                urunEkle();
                break;
            case 2:
                urunGuncelle();
                break;
            case 3:
                urunGoster();
                break;
            case 4:
                urunSil();
                break;
            case 5:
                printf("Cikis yapiliyor...\n");
                exit(0);
            default:
                printf("Yanlis secim\n");
        }
    }
}

void urunEkle() {
    struct urun u;
    FILE *dosya = fopen("urun.txt", "ab");
    if (!dosya) {
        printf("Dosya acilirken hata olustu!\n");
        return;
    }
    printf("Urun ID'si girin: ");
    scanf("%d", &u.id);
    printf("Urun ismi girin: ");
    scanf("%s", u.isim);
    printf("Urun fiyati girin: ");
    scanf("%f", &u.fiyat);
    printf("Urun stok miktarini girin: ");
    scanf("%d", &u.stok);
    fwrite(&u, sizeof(struct urun), 1, dosya);
    fclose(dosya);
    printf("Urun basariyla eklendi.\n");
}

void urunGuncelle() {
    struct urun u;
    int id, bulundu = 0;
    FILE *dosya = fopen("urun.txt", "rb+");
    if (!dosya) {
        printf("Urun bulunamadi.\n");
        return;
    }
    printf("Guncellenecek urun ID'sini girin: ");
    scanf("%d", &id);
    while (fread(&u, sizeof(struct urun), 1, dosya)) {
        if (u.id == id) {
            printf("Yeni urun ismini girin: ");
            scanf("%s", u.isim);
            printf("Yeni urun fiyatini girin: ");
            scanf("%f", &u.fiyat);
            printf("Yeni urun stok miktarini girin: ");
            scanf("%d", &u.stok);
            fseek(dosya, -sizeof(struct urun), SEEK_CUR);
            fwrite(&u, sizeof(struct urun), 1, dosya);
            printf("Urun basariyla guncellendi.\n");
            bulundu = 1;
            break;
        }
    }
    if (!bulundu) {
        printf("%d ID'li urun bulunamadi.\n", id);
    }
    fclose(dosya);
}

void urunGoster() {
    struct urun u;
    FILE *dosya = fopen("urun.txt", "rb");
    if (!dosya) {
        printf("Gosterilecek urun bulunamadi.\n");
        return;
    }
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Isim", "Fiyat", "Stok");
    printf("-----------------------------------------------------\n");
    while (fread(&u, sizeof(struct urun), 1, dosya)) {
        printf("%-10d %-20s %-10.2f %-10d\n", u.id, u.isim, u.fiyat, u.stok);
    }
    fclose(dosya);
}

void urunSil() {
    struct urun u;
    int id, bulundu = 0;
    FILE *dosya = fopen("urun.txt", "rb");
    FILE *gecici = fopen("gecici.txt", "wb");
    if (!dosya || !gecici) {
        printf("Urun bulunamadi.\n");
        if (dosya) fclose(dosya);
        if (gecici) fclose(gecici);
        return;
    }
    printf("Silinecek urun ID'sini girin: ");
    scanf("%d", &id);
    while (fread(&u, sizeof(struct urun), 1, dosya)) {
        if (u.id == id) {
            bulundu = 1;
            continue;
        }
        fwrite(&u, sizeof(struct urun), 1, gecici);
    }
    fclose(dosya);
    fclose(gecici);
    remove("urun.txt");
    rename("gecici.txt", "urun.txt");
    if (bulundu) {
        printf("Urun basariyla silindi.\n");
    } else {
        printf("%d ID'li urun bulunamadi.\n", id);
    }
}