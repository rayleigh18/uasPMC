#include <stdio.h>
#include "parse.h"
#include <time.h>

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


int main(){
    char* makan = "06062000";
    date now = getNowDate();
    date mein =  stringToTanggal(makan);
    printf("date lahir = %d %d %d\n", mein.day, mein.month, mein.year);
    printf("umur kamu adalah %d\n",findUmur(mein, now));

    return 0;
}