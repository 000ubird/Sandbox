/*
 ============================================================================
 Name        : Sandbox.c
 Author      : uBird
 Version     : 1.0
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
#define DEFAULT_PASSWD_LENGTH  8
#define MIN_LIMIT_PASSWD_LENGTH 3

extern int isContain(const char *, const char *);

int main(int argc, char *argv[]) {
    char base_char[BASE_CHAR_NUM];
    int i,j;
    int passwd_length = 0;

    //指定した長さのパスワードを生成する
    if(argc == 2){
        passwd_length = atoi(argv[1]);

        if(passwd_length < MIN_LIMIT_PASSWD_LENGTH){
            printf("Please specify a password of at least %d characters.\n",MIN_LIMIT_PASSWD_LENGTH);
            return EXIT_FAILURE;
        }
    }
    else{
        passwd_length = DEFAULT_PASSWD_LENGTH;
    }
    char passwd[passwd_length+1];

    printf("please wait.");
    fflush(stdout);

    //パスワード用生成文字列を作成
    snprintf(base_char,(size_t)BASE_CHAR_NUM, "%s%s%s", LARGE_ALPHABET, SMALL_ALPHABET, NUMBER);

    while(1){
        //実行するたびに値が変わるように
        sleep(1);
        srand((unsigned int)time(NULL));

        //パスワード生成
        //生成文字列からランダムに1文字選択
        for(i=0; i<passwd_length; i++){
            j = rand() % (BASE_CHAR_NUM-1) + 0; //0~61
            passwd[i] = base_char[j];
        }
        passwd[passwd_length] = '\0';

        //パスワード生成条件チェック
        if(isContain(passwd, LARGE_ALPHABET) &&
           isContain(passwd, SMALL_ALPHABET) &&
           isContain(passwd, NUMBER)){
            break;
        }
        else {
            printf(".");
            fflush(stdout);
            continue;
        }
    }

    printf("\n%s\n", passwd);

    return EXIT_SUCCESS;
}

