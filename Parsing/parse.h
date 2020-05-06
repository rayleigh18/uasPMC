#ifndef PARSE_H
#define PARSE_H

typedef struct date{
    int day;
    int month;
    int year;
}date;


typedef struct dataPen
{
    int nik;
    char* nama;
    char* tempatLahir;
    date tanggalLahir;
    int umur;
    char sex;
    char* goldar;
    char* status;
    char* work;
}dataPen;





#endif