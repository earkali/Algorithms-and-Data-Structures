    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Node{
        int veri;
        struct Node* next;
    };

    typedef struct Node node;
    node* head = NULL;

    void yazdir();
    void basaEkle(int veri);
    void arayaEkle(int veri, int sira);
    void sonaEkle(int veri);
    void dugumSil(int sira);

    int main()
    {
        int secim, veri, sira;
        while(1){
            printf("\n------Menu-----\n");
            printf("Listeyi goruntule\n");
            printf("1. Listeyi goruntule\n");
            printf("2. Basa eleman ekle\n");
            printf("3. Araya eleman ekle\n");
            printf("4. Sona eleman ekle\n");
            printf("5. Sira numarasina gore veri sil\n");
            printf("6. Cikis yap.\n");
            printf("Secim yapiniz.\n");
            scanf("%d", &secim);

            switch(secim){
                case 1:
                    yazdir();
                    break;
                case 2:
                    printf("Eklenecek veriyi girin: ");
                    scanf("%d", &veri);
                    basaEkle(veri);
                    break;
                case 3:
                    printf("Eklenecek veriyi girin: ");
                    scanf("%d", &veri);
                    printf("Hangi siraya eklenecek: ");
                    scanf("%d", &sira);
                    arayaEkle(veri, sira);
                    break;
                case 4:
                    printf("Eklenecek veriyi girin: ");
                    scanf("%d", &veri);
                    sonaEkle(veri);
                    break;
                case 5:
                    printf("Silinecek dugumun sira numarasini girin: ");
                    scanf("%d", &sira);
                    dugumSil(sira);
                    yazdir();
                    break;
                case 6:
                    printf("Cikis yapiliyor.\n");
                    exit(0);
                default:
                    printf("Gecersiz");
            }
        }
    }
    void yazdir() {
        node* temp = head;
        printf("liste: \n");
        while(temp != NULL) {
            printf("%d -> ", temp->veri);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    void basaEkle(int veri) {
        node* yeniDugum = (node*)malloc(sizeof(node));
        yeniDugum->veri = veri;
        yeniDugum->next = head;
        head = yeniDugum;
    }
    void sonaEkle(int veri) {
        node* yeniDugum = (node*)malloc(sizeof(node));
        yeniDugum->veri = veri;
        yeniDugum->next = NULL;
        if(head == NULL) {
            head = yeniDugum;
            return;
        }
        node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = yeniDugum;
    }
    void arayaEkle(int veri, int sira) {
        if(sira < 1) {
            printf("Gecersiz sira\n");
            return;
        }
        if(sira == 1 || head == NULL) {
            basaEkle(veri);
            return;
        }
        node* yeniDugum = (node*)malloc(sizeof(node));
        yeniDugum->veri = veri;

        node* temp = head;
        for(int i = 1; i < sira-1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Sira liste boyutundan buyuk\n");
            free(yeniDugum);
            return;
        }
        yeniDugum->next = temp->next;
        temp->next = yeniDugum;
    }
    void dugumSil(int sira) {
        if(head == NULL) {
            printf("Liste bos\n");
            return;
        }
        if(sira < 1) {
            printf("Gecersiz sira\n");
            return;
        }
        if(sira == 1) {
            node* temp = head;
            head = head->next;
            free(temp);
            return;
        }
        node* temp = head;
        node* prev = NULL;
        for(int i = 1; i < sira && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL) {
            printf("Sira liste boyutundan buyuk\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }