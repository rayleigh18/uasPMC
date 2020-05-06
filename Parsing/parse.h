#ifndef PARSE_H
#define PARSE_H
#include "../configuration.h"




date getNowDate();
int findUmur(date dateBorn, date dateNow);
date stringToTanggal(char* data);
date getNowDate();
listDataPen* parse(char* namaFile, date dateNow);







#endif