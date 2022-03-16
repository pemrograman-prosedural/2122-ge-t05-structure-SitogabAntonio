// 12S21015 - Sitogab Antonio Octavianus Girsang
// 12S21049 - Jesika Audina Purba

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Gender {
    MALE,
    FEMALE
};


typedef struct SMahasiswa Mahasiswa;
struct SMahasiswa {
    char nama[50];
    char NIM[10];
    int year;
    enum Gender gender;
};

void remove_newline_char(char* s) {
    while(*s && *s != '\n' && *s != '\r') s++;
    *s = 0;
}

int main(void) {
   
    char perintah[10];
    fgets(perintah, sizeof(perintah), stdin);
    remove_newline_char(perintah);
   
    if (strcmp(perintah, "register") != 0) {
        puts("0|0");
        return 0;
    }


    char stringData[1024];
    Mahasiswa listMahasiswa[50];    
    int jlhMale = 0, jlhFemale = 0;         
    int jlhMhs = 0;
    while (strcmp(stringData, "---") != 0) {
        fgets(stringData, sizeof(stringData), stdin);
        remove_newline_char(stringData);

        Mahasiswa dataMahasiswa;
        char* data = strtok(stringData, "|");
        int i = 0;                  
        while (data != NULL) {
            if      (i == 0) strcpy(dataMahasiswa.nama, data);
            else if (i == 1) strcpy(dataMahasiswa.NIM, data);
            else if (i == 2) dataMahasiswa.year = atoi(data);
            else if (i == 3) {
                if (strcmp(data, "MALE") == 0) {
                    dataMahasiswa.gender = MALE;
                    jlhMale++;
                }
                else if (strcmp(data, "FEMALE") == 0) {
                    dataMahasiswa.gender = FEMALE;
                    jlhFemale++;
                }
            }
            data = strtok(NULL, "|");
            i++;
        }
        listMahasiswa[jlhMhs] = dataMahasiswa;
        jlhMhs++;
    }
    
    printf("%d|%d", jlhMale, jlhFemale);
    return 0;
}
