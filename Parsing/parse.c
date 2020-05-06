#include <stdio.h>
#include "parse.h"

#define angka(c) ((int)(c)-'0')

date stringToTanggal(char* data){
    date temp;
    temp.day = 10*angka(data[0]) + angka(data[1]);
    temp.month = 10*angka(data[2]) + angka(data[3]);
    temp.year = 1000*angka(data[4]) + 100*angka(data[5]) +10*angka(data[6]) + angka(data[7]);
    return temp;
}


int main(){
    char* makan = "27102000";
    date mein = stringToTanggal(makan);
    printf("%d %d %d", mein.day, mein.month, mein.year);

    return 0;
}