#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../configuration.h"
#include "../Parsing/parse.h"
#include "search.h"

listDataPen* searchName(listDataPen* listPend, char* nama){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (strcmp(listPend->list[i].nama, nama)==0){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchNIK(listDataPen* listPend, int nik){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (listPend->list[i].nik==nik){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchTempatLahir(listDataPen* listPend, char* tempatLahir){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (strcmp(listPend->list[i].tempatLahir, tempatLahir)==0){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchTanggalLahir(listDataPen* listPend, date tanggalLahir){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (listPend->list[i].tanggalLahir.day==tanggalLahir.day
         && listPend->list[i].tanggalLahir.month==tanggalLahir.month
         && listPend->list[i].tanggalLahir.year==tanggalLahir.year){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}


listDataPen* searchUmur(listDataPen* listPend, int umur){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (listPend->list[i].umur==umur){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchSex(listDataPen* listPend, char sex){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (listPend->list[i].sex==sex){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchGolDar(listDataPen* listPend, char* goldar){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (strcmp(listPend->list[i].goldar, goldar)==0){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchStatus(listDataPen* listPend, int status){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (listPend->list[i].status==status){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}

listDataPen* searchWork(listDataPen* listPend, char* work){
    listDataPen* temp_list = initList();
    for (int i = 0; i < listPend->Neff; i++){
        if (strcmp(listPend->list[i].work, work)==0){
            addToList(temp_list,listPend->list[i]);
        }
    }
    return temp_list;
}


// int main(){
//     char* makan = "testData.csv";
//     listDataPen* listPend;
//     listPend = parse(makan, getNowDate());    

//     addDataFromFile(makan, getNowDate(), listPend);
//     printList(listPend);

//     listDataPen* listDataSearch = searchWork(listPend, "Pegawai Swasta");
//     printf("hasil Search :\n");
//     printList(listDataSearch);
//     perror("more details");
//     return 0;
// }
