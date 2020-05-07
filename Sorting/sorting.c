#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../configuration.h"
#include "../Parsing/parse.h"
#include "search.h"
#include "sorting.h"


void merge(listDataPen *f, int low,int middle, int high,int type, int order){

    int n1 = middle - low + 1;
    int n2 = high - middle;
    int i,j,k;
    dataPen Lf[n1], Rf[n2];

    for (i = 0; i < n1; i++){
        Lf[i] = f->list[low+i];
    }
    for (i = 0; i < n2; i++){
        Rf[i] = f->list[low+n1+i];
    }

    i = 0;
    j = 0;
    k = low;
    int left_i, right_j;
    while (i < n1 && j < n2){
        if (type == NIK_type){// add type here
            left_i = Lf[i].nik;
            right_j = Rf[j].nik;
        }
        else if (type == Umur_type){
            left_i = Lf[i].umur;
            right_j = Rf[j].umur;
        }
        else if (type == No_type){
            left_i = Lf[i].no;
            right_j = Rf[j].no;
        }
        else if (type == Goldar_type){
            if (strlen(Lf[i].goldar) == 1){
                left_i = (int)Lf[i].goldar[0];
            }
            else{
                left_i = (int)Lf[i].goldar[0] +(int)Lf[i].goldar[1];
            }

            if (strlen(Rf[j].goldar) == 1){
                right_j = (int)Rf[j].goldar[0];
            }
            else{
                right_j = (int)Rf[j].goldar[0] +(int)Rf[j].goldar[1];
            }
            
        }
        else if (type == Status_type){
            left_i = Lf[i].status;
            right_j = Rf[j].status;
        }
        else if (type == nama_type){
            if (strcmp(Lf[i].nama , Rf[j].nama) < 0){
                left_i = 0;
                right_j = 1;
            }
            else{
                right_j = 0;
                left_i = 1;
            }
        }
        else if (type == kerja_type){
            if (strcmp(Lf[i].work , Rf[j].work) < 0){
                left_i = 0;
                right_j = 1;
            }
            else{
                right_j = 0;
                left_i = 1;
            }
        }
        else if(type == tanggal_type){
            if (Lf[i].tanggalLahir.year < Rf[i].tanggalLahir.year){
                left_i = 0;
                right_j = 1;
            }
            else if (Lf[i].tanggalLahir.year > Rf[i].tanggalLahir.year){
                left_i = 1;
                right_j = 0;
            }
            else{
                if (Lf[i].tanggalLahir.month < Rf[i].tanggalLahir.month){
                    left_i = 0;
                    right_j = 1;
                }
                else if (Lf[i].tanggalLahir.month > Rf[i].tanggalLahir.month){
                    left_i = 1;
                    right_j = 0;
                }
                else{
                    if (Lf[i].tanggalLahir.day <= Rf[i].tanggalLahir.day){
                        left_i = 0;
                        right_j = 1;
                    }
                    else if (Lf[i].tanggalLahir.day > Rf[i].tanggalLahir.day){
                        left_i = 1;
                        right_j = 0;
                    }
                }
            }
            
        }
        
        else if (type == tempat_type){
            if (strcmp(Lf[i].tempatLahir , Rf[j].tempatLahir) < 0){
                left_i = 0;
                right_j = 1;
            }
            else{
                right_j = 0;
                left_i = 1;
            }
        }
        if (order*left_i <= order*right_j){
            f->list[k] = Lf[i];
            i++;
        }
        else{
            f->list[k] = Rf[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        f->list[k] = Lf[i];
        i++;
        k++;
    }
    while (j < n2){
        f->list[k] = Rf[j];
        j++;
        k++;
    }
}
void sort(listDataPen *dataPen, int left, int right, int type, int order){// buat doublenya dulu, biar ga berubah
    if (left < right){
        int middle = (left + right)/2;
        sort(dataPen, left, middle,type, order);
        sort(dataPen,middle+1,right,type, order);
        merge(dataPen, left, middle, right,type, order);
    }
}

// int main(){
//     char* makan = "testData.csv";
//     listDataPen* listPend;
//     listPend = parse(makan, getNowDate());    

//     addDataFromFile(makan, getNowDate(), listPend);
//     printList(listPend);

//     listDataPen* listDataSearch = searchWork(listPend, "Pegawai Swasta");
//     printf("Hasil Search :\n");
//     printList(listDataSearch);


//     listDataPen* listSort = listPend;
//     sort(listPend, 0, listSort->Neff - 1, 1,ASCENDING);
    
//     printf("Hasil Sort \n");
//     printList(listSort);
//     perror("more details");
//     return 0;
// }
