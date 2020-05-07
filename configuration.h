#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <stdlib.h>

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
    char nama[100];
    char tempatLahir[100];
    date tanggalLahir;
    int umur;
    char sex;
    char goldar[4];
    int status;
    char work[100];
}dataPen;

typedef struct listDataPen{
    dataPen* list;
    int Neff;
}listDataPen;

char* askFileName();

char* header;
#endif