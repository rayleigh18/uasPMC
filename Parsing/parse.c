#include <stdio.h>
#include <time.h>
#include "parse.h"

#include "string.h"
#include "stdlib.h"
#define angka(c) ((int)(c)-'0')

date stringToTanggal(char* data){
    date temp;
    temp.day = 10*angka(data[0]) + angka(data[1]);
    temp.month = 10*angka(data[2]) + angka(data[3]);
    temp.year = 1000*angka(data[4]) + 100*angka(data[5]) +10*angka(data[6]) + angka(data[7]);
    return temp;
}

date getNowDate(){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    date temp;
    temp.day = local->tm_mday;
    temp.month = local->tm_mon + 1;
    temp.year  = local->tm_year + 1900;

    return temp;    
}

int findUmur(date dateBorn, date dateNow){
    int temp = dateNow.year - dateBorn.year;
    if (dateBorn.month == dateNow.month){
        if (dateBorn.day < dateNow.day){
            return temp - 1;
        }
    }
    else if (dateBorn.month > dateNow.month){
        return temp - 1;
    }
    return temp;
}

listDataPen* initList(){
    listDataPen* temp = (listDataPen*)malloc(sizeof(listDataPen));
    
    temp->list = (dataPen*)malloc(10*sizeof(dataPen));
    temp->Neff = 0; 
    return temp;
}
void printList(listDataPen* listPend, int state){
    printf("%3s %10s %20s %20s %10s %5s %4s %6s %11s %20s\n", "No", "NIK",
    "Nama", "Tempat Lahir", "Tanggal Lahir", "Umur", "Sex", "Darah", "Status", "Pekerjaan");
    for (int i = 0; i < listPend->Neff; i++){
        dataPen temp = listPend->list[i];
        printf("%3d %10d %20s %20s    %2d/%2d/%4d %5d %4c %6s %11s %20s\n",
            temp.no, temp.nik, temp.nama, temp.tempatLahir,
            temp.tanggalLahir.day, temp.tanggalLahir.month, temp.tanggalLahir.year,
            temp.umur, temp.sex, temp.goldar, (temp.status == 1) ? "Kawin" : "Tidak Kawin" 
            , temp.work  
        );
    }
    if (state == STATE_PRINT){
        int pilihan;
        printf("Masukkan ke File?\n");
        printf("0. Tidak   1. Ya \n");
        printf("Jawaban anda:");
        scanf("%d",&pilihan);
        char fileName[1000];
        if (pilihan == 1){
            strcpy(fileName, askFileName());
            FILE *f = fopen(fileName, "w");

            fprintf(f,"%s",header);//header
            for (int i = 0; i < listPend->Neff; i++){

            dataPen temp = listPend->list[i];
            fprintf(f,"\n");
            fprintf(f,"%d;%d;%s;%s;%s%d%s%d%s%s%s%d;%d;%c;%s;%s;%s",
                temp.no, temp.nik, temp.nama, temp.tempatLahir,
                (temp.tanggalLahir.day < 10) ? "0" :"",
                temp.tanggalLahir.day,
                (temp.tanggalLahir.month < 10) ? "0" :"",
                temp.tanggalLahir.month,
                (temp.tanggalLahir.year < 10) ? "0" :"",
                (temp.tanggalLahir.year < 100) ? "0" :"",
                (temp.tanggalLahir.year < 1000) ? "0" :"",
                temp.tanggalLahir.year,
                temp.umur, temp.sex, temp.goldar, (temp.status == 1) ? "Kawin" : "Tidak Kawin" 
                , temp.work  
            );
            fclose(f);
           }
        }
    }

}

void addToList(listDataPen* listPend, dataPen dataPenduduk){
    
    listPend->list = (dataPen*)realloc(listPend->list, sizeof(dataPen)*((listPend->Neff) +1));
    dataPenduduk.no = (listPend->Neff) + 1;
    (listPend->list)[listPend->Neff] = dataPenduduk;
    listPend->Neff += 1;
    //printList(listPend);
}

dataPen processLine(char* line, date dateNow){
    dataPen temp_pend;
    if (line[strlen(line)-1] == '~'){
        line[strlen(line)-1] = '\0';
    } // menghapus tilde
    char* tok;

    tok = strtok(line, ";");
    temp_pend.no = atoi(tok);    

    tok = strtok(NULL, ";");
    temp_pend.nik = atoi(tok);    

    tok = strtok(NULL, ";");    
    strcpy(temp_pend.nama, tok);    

    tok = strtok(NULL, ";");
    strcpy(temp_pend.tempatLahir, tok);    

    tok = strtok(NULL, ";");
    temp_pend.tanggalLahir = stringToTanggal(tok);

    tok = strtok(NULL, ";");
    temp_pend.umur = findUmur(temp_pend.tanggalLahir, dateNow);

    tok = strtok(NULL, ";");
    temp_pend.sex = tok[0];

    tok = strtok(NULL, ";");
    strcpy(temp_pend.goldar, tok);

    tok = strtok(NULL, ";");
    if (tok[0] == 'K' || tok[0] == 'k'){
        temp_pend.status = KAWIN;
    }
    else temp_pend.status = TIDAK_KAWIN;

    tok = strtok(NULL, ";");

    strcpy(temp_pend.work, tok);

    return temp_pend;
}



listDataPen* parse(char* namaFile, date dateNow){
    FILE* f = fopen(namaFile, "r");
    
    listDataPen *listPen = initList();
    
    char line[1024];
    fgets(line,1024,f);
    while (fgets(line, 1024, f)){
        //printf("debug\n");
        char* temp_line = strtok(line,"\n");

        
        dataPen temp_pend = processLine(temp_line, dateNow);

        addToList(listPen, temp_pend);
    }

    fclose(f);

    return listPen;
}

void* addDataFromFile(char* namaFile, date dateNow, listDataPen *listPen){
    FILE* f = fopen(namaFile, "r");
    
    char line[1024];
    fgets(line,1024,f);
    while (fgets(line, 1024, f)){
        //printf("debug\n");
        char* temp_line = strtok(line,"\n");
        dataPen temp_pend = processLine(temp_line, dateNow);

        addToList(listPen, temp_pend);
    }

    fclose(f);

    return listPen;
}

