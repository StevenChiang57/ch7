#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    int c;

    while((c = getchar()) != EOF){
        if(strcmp(argv[0], "lower") == 0){
            putchar(tolower(c));
        }
        else{
            putchar(toupper(c));
        }
        
    }
}