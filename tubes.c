// *********************
// Tubes bang grant membuat CRUD sederhana melalui c
// Anggota:
// 1. Alya Mufthia Roito
// 2. Andreas
// 3. Andrian James Siregar
// 4. Delrico Lie
// 5. Siti Alya Revano
// *********************

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct mahasiswa
{
    char nama[30];
    int nim;
    char kom;
    char tempatLahir[50];
    char bidangMinat[50];
    char matkulFav[30];
};

void tambah()
{
    struct mahasiswa data;

    FILE *fptr;

    fptr = fopen("dataMhs.txt", "a");
    if (fptr == NULL)
    {
        printf("File tidak ditemukan atau tidak dapat dibuka.\n");
        exit(1);
    }

    int check = 0;
    do
    {
        check = 0;
        printf("Masukkan nama: ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strcspn(data.nama, "\n")] = '\0';
        for (int i = 0; data.nama[i] != '\0'; i++)
        {
            if (isalpha(data.nama[i]))
            {
                check = 1;
            }
            else if (data.nama[i] == ' ')
            {
                check = 1;
            }
            else
            {
                check = 0;
                break;
            }
        }

        check == 1 ? fprintf(fptr, "%s-", data.nama) : printf("Nama hanya boleh alphabet.\n");
    } while (check == 0);

    do
    {
        printf("Masukkan NIM: ");
        scanf("%d", &data.nim);
        if (data.nim >= 100000000 && data.nim <= 999999999)
        {
            fprintf(fptr, "%d-", data.nim);
            check = 1;
        }
        else
        {
            printf("NIM hanya boleh 9 angka.\n");
            check = 0;
            fflush(stdin);
        }
    } while (check == 0);

    char handler;
    do
    {
        printf("Masukkan KOM: ");
        if (scanf(" %c%c", &data.kom, &handler) == 2 && handler == '\n' && isalpha(data.kom))
        {
            check = 1;
            fprintf(fptr, "%c-", toupper(data.kom));
        }
        else
        {
            printf("Masukkan 1 karakter & hanya huruf\n");
            check = 0;
            fflush(stdin);
        }

    } while (check == 0);

    printf("Masukkan Tempat Lahir: ");
    fgets(data.tempatLahir, sizeof(data.tempatLahir), stdin);
    data.tempatLahir[strcspn(data.tempatLahir, "\n")] = '\0';
    fprintf(fptr, "%s-", data.tempatLahir);

    printf("Masukkan Bidang yang Diminati: ");
    fgets(data.bidangMinat, sizeof(data.bidangMinat), stdin);
    data.bidangMinat[strcspn(data.bidangMinat, "\n")] = '\0';
    fprintf(fptr, "%s-", data.bidangMinat);

    printf("Masukkan Matkul Favorit: ");
    fgets(data.matkulFav, sizeof(data.matkulFav), stdin);
    data.matkulFav[strcspn(data.matkulFav, "\n")] = '\0';
    fprintf(fptr, "%s\n", data.matkulFav);

    fclose(fptr);
}

void tampil()
{
    FILE *readF;

    readF = fopen("dataMhs.txt", "r");
    if (readF == NULL)
    {
        printf("File tidak ditemukan atau tidak dapat dibuka.\n");
        exit(1);
    }

    struct mahasiswa data;
    char buffer[200];

    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s| %-10s| %-5s| %-30s| %-25s| %-15s|\n", "Nama", "NIM", "KOM", "Tempat Lahir", "Bidang yang Diminati", "Matkul Favorit");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    int i;
    while (fgets(buffer, sizeof(buffer), readF) != NULL)
    {
        sscanf(buffer, "%20[^-]-%d-%c-%30[^-]-%25[^-]-%15[^\n]",
               data.nama, &data.nim, &data.kom, data.tempatLahir, data.bidangMinat, data.matkulFav);
        printf("| %-20s| %-10d| %-5c| %-30s| %-25s| %-15s|\n", data.nama, data.nim, data.kom, data.tempatLahir, data.bidangMinat, data.matkulFav);
    }
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    fclose(readF);
}

int main()
{
    int resp;
    do
    {
        int pilihan;

        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Keluar\n");

        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            fflush(stdin);
            system("cls");
            tambah();
            break;
        case 2:
            system("cls");
            tampil();
            break;
        case 3:
            system("cls");
            printf("Byeeee\n");
            break;

        default:
            system("cls");

            printf("Minim Literasi\n");
        }
        do
        {
            printf("Lagi? (y/t): ");
            fflush(stdin);
            resp = getchar();

        } while (resp != tolower('Y') && resp != tolower('T'));

    } while (resp == tolower('y'));

    return 0;
}