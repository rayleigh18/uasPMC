#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "Parsing/parse.h"
#include "configuration.h"
#include "CreateUpdateDelete/delete.h"
#include "CreateUpdateDelete/search.h"
#include "CreateUpdateDelete/update.h"
#include "CreateUpdateDelete/adding.h"
#include "Sorting/sorting.h"
void print(char* str){
    printf("%s\n",str);
}

char* header = "No;NIK;NamaLengkap;TempatLahir;TanggalLahir;Umur;JenisKelamin;GolonganDarah;Status;Pekerjaan";

char* askFileName(){
    fflush(stdin);
    char* tempFileName;

    printf("Masukkan nama File :");    
    tempFileName = (char*)malloc(1000*sizeof(char));
    scanf("%[^\n]%*c", tempFileName);
    FILE *f;
    f = fopen(tempFileName, "r");
    while (f == NULL){
        printf("File tidak ada\nMasukkan nama File :");    
        tempFileName = (char*)malloc(1000*sizeof(char));
        scanf("%[^\n]%*c", tempFileName);
        f = fopen(tempFileName, "r");
    }
    fclose(f);
    return tempFileName;
}



int menu();
void menuSearch();

int main(){
    print("Selamat Datang di Program Mantap");
    int menu_now = menu();
    char fileName[1000];
    date date_now = getNowDate();

    listDataPen *list_penduduk = initList();
    while (menu_now != 99){
        if (menu_now == 1){
            strcpy(fileName, askFileName());
            list_penduduk = parse(fileName, date_now);
            printList(list_penduduk, STATE_NOT_PRINT);
        }
        else if(menu_now == 2){
            strcpy(fileName, askFileName());
            addDataFromFile(fileName, date_now, list_penduduk);
            printList(list_penduduk,STATE_PRINT);
        }
        else if (menu_now == 3){
            addDataToListPen(list_penduduk, date_now);
        }
        else if (menu_now == 4){
            menuSearch(list_penduduk);
        }
        else if (menu_now == 5){
            update(list_penduduk, date_now);
        }
        else if(menu_now == 6){
            listDataPen* sortData = list_penduduk;
            print("1. Ascending 2. Descending");
            int order_in, order;

            printf("Masukkan order sort: ");
            scanf("%d", &order_in);
            if (order_in == 1){
                order = ASCENDING;
            }
            else order = DESCENDING;

            print("Daftar yang bisa\n1. NIK   \n2. Umur  \n3. No  \n4. Goldar  \n5. Status \n6. Nama \n7. Pekerjaan  \n8. Tanggal  \n9. Tempat Lahir");
            int type;
            printf("Masukkan tipe: ");
            scanf("%d", &type);

            sort(sortData, 0, (sortData->Neff)-1,type,order);

            printList(sortData,STATE_PRINT);
            
        }
        else if (menu_now == 7){
            printList(list_penduduk,STATE_PRINT);
        }
        else if (menu_now == 8){
            delete(list_penduduk, date_now);
        }
        
        menu_now = menu();
    }
    

    return 0;
}

int menu(){
    
    print("Pilih Menu");
    print("1. Masukkan data dari csv luar");
    print("2. Tambah data dari csv luar");
    print("3. Masukkan data");
    print("4. Cari data");
    print("5. Update data");
    print("6. Temukan urutan data");
    print("7. Print data");
    print("8. Delete Data");
    // print("9. Save");
    print("99. Exit");
    //not yet implemented
    int total_menu = 8;
    int menu_pilihan;

    printf("Masukkan menu yang valid:");
    scanf("%d", &menu_pilihan);

    while ((menu_pilihan > total_menu && menu_pilihan != 99) || menu_pilihan < 1 ){
        printf("Menu tidak valid\nMasukkan menu yang valid:");
        scanf("%d", &menu_pilihan);
    }
    return menu_pilihan;
}

void menuSearch(listDataPen *list_penduduk){
    print("Tentukan data yang ingin dicari");
    print("1. NIK");
    print("2. Nama");
    print("3. Tempat Tanggal Lahir");
    print("4. Tanggal Lahir");
    print("5. Umur");
    print("6. Jenis Kelamin");
    print("7. Golongan Darah");
    print("8. Status Perkawinan");
    print("9. Pekerjaan");
    int total_menu = 9;
    int menu_pilihan;// add while

    printf("Masukkan menu yang valid:");
    scanf("%d", &menu_pilihan);

    while (menu_pilihan > total_menu || menu_pilihan < 1){
        printf("Masukkan menu yang valid:");
        scanf("%d", &menu_pilihan);
    }
    fflush(stdin);
    listDataPen* temp_list = list_penduduk;
    if (menu_pilihan == 1){
        int nik_temp;
        printf("Masukkan NIK yang ingin dicari:");
        scanf("%d", &nik_temp);
        temp_list = searchNIK(temp_list, nik_temp);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    else if (menu_pilihan == 2){
        char name[100];
        printf("Masukkan Nama yang ingin dicari:");
        scanf("%[^\n]%*c", name);
        temp_list = searchName(temp_list, name);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    else if (menu_pilihan == 3){
        char tempat[100];
        printf("Masukkan Tempat Lahir yang ingin dicari:");
        scanf("%[^\n]%*c", tempat);
        temp_list = searchTempatLahir(temp_list, tempat);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    else if (menu_pilihan == 4){
        printf("Masukkan Tanggal Lahir Dicari:");
        date temp_date; // need pemeriksa
        scanf("%d",&(temp_date.day));
        printf("Masukkan Bulan Lahir Dicari:");
        scanf("%d",&(temp_date.month));
        printf("Masukkan Tahun Lahir Dicari:");
        scanf("%d",&(temp_date.year));

        temp_list = searchTanggalLahir(temp_list, temp_date);

        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    
    else if (menu_pilihan == 5){
        int age;
        printf("Masukkan Umur :");
        scanf("%d", &age);
        temp_list = searchUmur(temp_list, age);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    
    else if (menu_pilihan == 6){
        char sex;
        fflush(stdin);
        printf("Masukkan Jenis Kelamin yang ingin dicari: ");
        scanf("%c", &sex);
        temp_list = searchSex(temp_list, sex);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }

    else if (menu_pilihan == 7){
        char goldar[4];
        printf("Masukkan Golongan Darah yang Dicari: ");
        scanf("%s",goldar);

        while (strcmp(goldar, "A") && strcmp(goldar, "B") && strcmp(goldar, "AB") && strcmp(goldar, "O")){
            printf("Golongan darah yang anda masukkan salah\nMasukkan Golongan Darah yang Dicari:");
            scanf("%s",goldar);
        }
        temp_list = searchGolDar(temp_list, goldar);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }

    else if (menu_pilihan == 8){
        printf("Apakah anda mencari yang sudah menikah?\n");
        printf("0. Tidak  1. Ya");
        int nikah;
        scanf("%d", &nikah);
        while (nikah != 0 && nikah != 1){
            printf("Apakah anda mencari yang sudah menikah?\n");
            printf("0. Tidak  1. Ya");
            int nikah;
            scanf("%d", &nikah);
        }
        temp_list = searchStatus(temp_list, nikah);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    else if (menu_pilihan == 9){
        printf("Masukkan Pekerjaan yang Anda Cari:");
        fflush(stdin);
        char tempWork[100];
        scanf("%[^\n]%*c", tempWork);
        temp_list = searchWork(temp_list, tempWork);
        if (temp_list->Neff == 0){
            print("Tidak ditemukan\n");
        }
        else{
            printList(temp_list,STATE_PRINT);
        }
    }
    
    
}