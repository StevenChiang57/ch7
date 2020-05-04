#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 200

// clang 7-6.c -o test
void compare(FILE * fin1, FILE *fin2){
    char *p1, *p2;
    char temp1[MAXLINE], temp2[MAXLINE];
    do{
        p1 = fgets(temp1, MAXLINE, fin1);
        p2 = fgets(temp2, MAXLINE, fin2);
        if (strcmp(temp1, temp2) != 0){
            printf("The first difference in the files\n");
            printf("File1: %s", temp1);
            printf("File2: %s", temp2);
            p1 = p2 = NULL;
        }
    }while(p1 != NULL || p2 != NULL);
}

int main(int argc, char* argv[]){
    if(argc != 3) { printf("./useage file1 file2"); exit(1); }

    FILE *fin1 = fopen(argv[1], "r");
    FILE *fin2 = fopen(argv[2], "r");

    if(fin1 == NULL) { printf("cannot read first file"); exit(1); }
    if(fin2 == NULL) { printf("cannot read second file"); exit(1); }
    compare(fin1, fin2);
    
}