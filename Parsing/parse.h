#ifndef PARSE_H
#define PARSE_H

#define GOLDAR_A  0
#define GOLDAR_B  1
#define GOLDAR_AB 2
#define GOLDAR_O  3

#define KAWIN 1
#define TIDAK_KAWIN 0

typedef struct date{
    int day;
    int month;
    int year;
}date;


typedef struct dataPen
{
    int no;
    int nik;
    char* nama;
    char* tempatLahir;
    date tanggalLahir;
    int umur;
    char sex;
    char* goldar;
    int status;
    char* work;
}dataPen;

typedef struct listDataPen{
    dataPen* list;
    int Neff;
}listDataPen;



date getNowDate();
int findUmur(date dateBorn, date dateNow);






#endif