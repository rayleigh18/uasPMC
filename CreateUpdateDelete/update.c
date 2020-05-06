#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../configuration.h"
#include "../Parsing/parse.h"
#include "update.h"
#include "search.h"

void update(listDataPen* listPen, date dateNow){
    printf("Masukkan NIK anda :");
    int nik;
    
    scanf("%d",&nik);

    listDataPen* listNik = searchNIK(listPen, nik);

    if (nik == -1){
        return;
    }

    while(listNik->Neff == 0){
        printf("NIK yang anda masukkan salah\nMasukkan NIK anda :");
    
        scanf("%d",&nik);
        if (nik == -1){
           return;
        }

        listDataPen* listNik = searchNIK(listPen, nik);
        
    }

    printf("Tentukan yang mana data anda:\n");
    printList(listNik);
    int pilihan;
    scanf("%d", &pilihan);
    while (pilihan < 1 || pilihan > (listNik->Neff)){
        printf("Masukkan data yang benar\nTentukan yang mana data anda:\n");
        scanf("%d", &pilihan);
    }
    dataPen* tempPend = listNik->list + pilihan - 1;
    printf("Pilih yang anda ingin ubah :\n");
    printf("0. NIK\n1. Nama\n2. Tempat Lahir\n3. Tanggal Lahir\n4. Jenis Kelamin\n5. Golongan Darah\n6. Status\n7. Pekerjaan\n");
    
    scanf("%d",&pilihan);
    // Bagian memasukkan pilihan, next tambahin pakai while gitu
    if (pilihan == 1){  
        printf("Masukkan nama baru:");
        fflush(stdin);
        scanf("%[^\n]%*c", (tempPend->nama));
    }
    if (pilihan == 2){  
        printf("Masukkan tempat Lahir baru:");
        fflush(stdin);
        scanf("%[^\n]%*c", (tempPend->tempatLahir));
    }
    if (pilihan == 3){  
        printf("Masukkan Tanggal Lahir baru:");
        date temp_date; // need pemeriksa
        scanf("%d",&(temp_date.day));
        printf("Masukkan Bulan Lahir baru:");
        scanf("%d",&(temp_date.month));
        printf("Masukkan Tahun Lahir baru:");
        scanf("%d",&(temp_date.year));
        tempPend->tanggalLahir = temp_date;
        tempPend->umur = findUmur(temp_date, dateNow);
    }
    if (pilihan == 4){
        int sex_temp;
        printf("Masukkan Jenis Kelamin:\n");
        printf("1. Pria\n2Wanita\n");
        fflush(stdin);
        scanf("%d",&sex_temp);// supaya gampang, dibuat integer saja
        while (sex_temp != 1 && sex_temp != 2){// udah pemeriksa, belum test
            printf("Jenis kelamin tidak dikenali\nMasukkan Jenis Kelamin:");
            printf("1. Pria\n2Wanita\n");
            fflush(stdin);
            scanf("%d",&sex_temp);
        }
        tempPend->sex = sex_temp == 1 ? 'L': 'P' ;
    }
    if (pilihan == 5){
        char goldar[4];
        printf("Masukkan Golongan Darah yang baru:");
        scanf("%s",goldar);

        while (strcmp(goldar, "A") && strcmp(goldar, "B") && strcmp(goldar, "AB") && strcmp(goldar, "O")){
            printf("Golongan darah yang anda masukkan salah\nMasukkan Golongan Darah yang baru:");
            scanf("%s",goldar);
        }
        strcpy(tempPend->goldar, goldar);
    }

    if (pilihan == 6){
        printf("Apakah anda sudah menikah?\n");
        printf("0. Tidak  1. Ya");
        int nikah;
        scanf("%d", &nikah);
        while (nikah != 0 && nikah != 1){
            printf("Apakah anda sudah menikah?\n");
            printf("0. Tidak  1. Ya");
            int nikah;
            scanf("%d", &nikah);
        }
        tempPend->status = nikah;
    }

    if (pilihan == 7){  
        printf("Masukkan Pekerjaan Anda:");
        fflush(stdin);
        scanf("%[^\n]%*c", (tempPend->work));
    }   
    // ngeliat apakah sudah berubah
    printList(listNik);
}

// int main(){
//     char* makan = "testData.csv";
//     listDataPen* listPend;
//     listPend = parse(makan, getNowDate());    

//     addDataFromFile(makan, getNowDate(), listPend);
//     printList(listPend);

//     listDataPen* listDataSearch = searchWork(listPend, "Pegawai Swasta");
//     printf("hasil Search :\n");
//     printList(listDataSearch);
//     update(listPend, getNowDate());
//     perror("more details");
//     return 0;
// }