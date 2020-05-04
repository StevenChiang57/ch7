#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 100
int pagenum = 1;
// clang 7-8.c -o test
void print(FILE *fin, char* heading){
    char line[MAXLINE];
    printf("\f");
    printf("%s heading              Page: %d\n\n", heading, pagenum);
    ++pagenum;
    while(fgets(line, MAXLINE, fin) != NULL){
        printf("%s", line);
    }
}

int main(int argc, char *argv[]){
    if(argc == 1){ printf("no files given\n"); exit(1); }
    FILE *fin;
    int count = 0;
    while(++count < argc){
        if((fin = fopen(argv[count], "r")) == NULL){ printf("cant open %s file\n", argv[count]); exit(1); }
        print(fin, argv[count]);
        printf("\n");
    }
}