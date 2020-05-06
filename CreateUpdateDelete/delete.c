#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../configuration.h"
#include "../Parsing/parse.h"
#include "update.h"
#include "search.h"

void deleteInList(listDataPen* listPen, int urutan){
    listPen->Neff -= 1;
    for (int i = urutan; i < listPen->Neff; i++){
        listPen->list[i] = listPen->list[i+1];
        listPen->list[i].no -= 1;
    }
}

void delete(listDataPen* listPen, date dateNow){
    printf("Masukkan NIK yang ingin dihapus");
    int nik;
    scanf("%d", &nik);
    printList(searchNIK(listPen, nik));
    int nomorHapus;
    listDataPen* temp_list = initList();
    
    printf("Pilih nomor yang ingin dihapus (-1 jika ingin menghapus semua): ");
    scanf("%d", &nomorHapus);
    int count = 0;
    if (nomorHapus != -1){
        for (int i = 0; i < listPen->Neff; i++){
            if (listPen->list[i].nik==nik){
                count += 1;
                if (count == nomorHapus){
                    deleteInList(listPen, i);
                    break;
                }
            }
        }
    }
    else{
        for (int i = 0; i < listPen->Neff; i++){
            if (listPen->list[i].nik==nik){
                deleteInList(listPen, i);
            }
        }
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
//     delete(listPend, getNowDate());
//     printList(listPend);
//     perror("more details");
//     return 0;
// }