#ifndef SEARCH_H
#define SEARCH_H
#include "../configuration.h"
listDataPen* searchName(listDataPen* listPend, char* nama);
listDataPen* searchNIK(listDataPen* listPend, int nik);
listDataPen* searchTempatLahir(listDataPen* listPend, char* tempatLahir);
listDataPen* searchTanggalLahir(listDataPen* listPend, date tanggalLahir);
listDataPen* searchUmur(listDataPen* listPend, int umur);

listDataPen* searchSex(listDataPen* listPend, char sex);
listDataPen* searchGolDar(listDataPen* listPend, char* goldar);
listDataPen* searchStatus(listDataPen* listPend, int status);
listDataPen* searchWork(listDataPen* listPend, char* work);


#endif