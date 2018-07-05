/*
 ============================================================================
 Name        : Sandbox.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

//パスワード生成用文字列を選べるように分割
#define LARGE_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ" //26文字
#define SMALL_ALPHABET "abcdefghijklmnopqrstuvwxyz" //26文字
#define NUMBER         "1234567890" //10文字
#define BASE_CHAR_NUM  62
#define PASSWD_LENGTH  8

int isContain(const char *, const char *);

int main(void) {
    char base_char[BASE_CHAR_NUM+1] = "";
    char passwd[PASSWD_LENGTH+1] = "";
    int i,j;

    //パスワード用生成文字列を作成
    snprintf(base_char,(size_t)BASE_CHAR_NUM, "%s%s%s", LARGE_ALPHABET, SMALL_ALPHABET, NUMBER);


    while(1){
        //実行するたびに値が変わるように
        srand((unsigned int)time(NULL));

        //パスワード生成
        //生成文字列からランダムに1文字選択
        for(i=0; i<PASSWD_LENGTH; i++){
            j = rand() % (BASE_CHAR_NUM) + 0; //0~61
            snprintf(passwd, (size_t)PASSWD_LENGTH, "%s%c", passwd, base_char[j]);
            //printf("%c", base_char[j]); //Debug
        }

        printf("\n%s\n", passwd);
        //printf("12345678\n");

        //パスワード生成条件チェック
        if(isContain(passwd, LARGE_ALPHABET) &&
           isContain(passwd, SMALL_ALPHABET) &&
           isContain(passwd, NUMBER)){
            printf("ok");
            break;
        }
        else {
            printf("ng");
            break;
            //sleep(1); //これを入れるとバグる
        }
    }

    printf("\n%s\n", passwd);
    printf("12345678\n");

    return EXIT_SUCCESS;
}

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
