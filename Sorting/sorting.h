#ifndef SORTING_H
#define SORTING_H

#define NIK_type 1
#define Umur_type 2
#define No_type 3
#define Goldar_type 4
#define Status_type 5
#define nama_type 6
#define kerja_type 7
#define tanggal_type 8
#define tempat_type 9

#define ASCENDING 1
#define DESCENDING -1
void sort(listDataPen *dataPen, int left, int right, int type, int order);

#endif