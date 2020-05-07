#ifndef PARSE_H
#define PARSE_H
#include "../configuration.h"




date getNowDate();
int findUmur(date dateBorn, date dateNow);
date stringToTanggal(char* data);
date getNowDate();
listDataPen* parse(char* namaFile, date dateNow);
listDataPen* initList();
void printList(listDataPen* listPend, int state);
void addToList(listDataPen* listPend, dataPen dataPenduduk);
void* addDataFromFile(char* namaFile, date dateNow, listDataPen *listPen);







#endif