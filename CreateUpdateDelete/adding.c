#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../configuration.h"
#include "../Parsing/parse.h"
#include "update.h"
#include "search.h"
#include "adding.h"

void addDataToListPen(listDataPen *listPen, date dateNow){
    printf("Masukkan NIK");
    dataPen *tempPend = (dataPen*)malloc(sizeof(dataPen));
    scanf("%d",&(tempPend->nik));

    printf("Masukkan nama:");
    fflush(stdin);
    scanf("%[^\n]%*c", (tempPend->nama));

    printf("Masukkan tempat Lahir baru:");
    fflush(stdin);
    scanf("%[^\n]%*c", (tempPend->tempatLahir));

    printf("Masukkan Tanggal Lahir baru:");
    date temp_date; // need pemeriksa
    scanf("%d",&(temp_date.day));
    printf("Masukkan Bulan Lahir baru:");
    scanf("%d",&(temp_date.month));
    printf("Masukkan Tahun Lahir baru:");
    scanf("%d",&(temp_date.year));
    tempPend->tanggalLahir = temp_date;
    
    tempPend->umur = findUmur(temp_date, dateNow);

    int sex_temp;
    printf("Masukkan Jenis Kelamin:\n");
    printf("1. Pria\n2Wanita\n");
    fflush(stdin);
    scanf("%d",&sex_temp);// supaya gampang, dibuat integer saja
    while (sex_temp != 1 && sex_temp != 2){
        printf("Jenis kelamin tidak dikenali\nMasukkan Jenis Kelamin:");
        printf("1. Pria\n2. Wanita\n");
        fflush(stdin);
        scanf("%d",&sex_temp);
    }
    tempPend->sex = sex_temp == 1 ? 'L': 'P' ;

    char goldar[4];
    printf("Masukkan Golongan Darah yang baru:");
    scanf("%s",goldar);

    while (strcmp(goldar, "A") && strcmp(goldar, "B") && strcmp(goldar, "AB") && strcmp(goldar, "O")){
        printf("Golongan darah yang anda masukkan salah\nMasukkan Golongan Darah yang baru:");
        scanf("%s",goldar);
    }
    strcpy(tempPend->goldar, goldar);

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

    printf("Masukkan Pekerjaan Anda:");
    fflush(stdin);
    scanf("%[^\n]%*c", (tempPend->work));

    addToList(listPen,*tempPend);
    printf("debug");
}