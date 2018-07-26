#include <stdio.h>
#include <string.h>

int isContain(const char *, const char *);

int isContain(const char *str1,const char *str2){
    int i,j;

    for(i=0; i<strlen(str1); i++){
        for(j=0; j<strlen(str2); j++){

            //printf("%c %c \n",str1[i], str2[j]);
            if(str1[i] == str2[j]){
                //含まれていた
                return 1;
            }
        }
    }

    //含まれていなかった
    return 0;
}
