#include "main.h"

void input_data(int *m, FILE *f){
    int count = 0, temp = 0, trigger = 0;
    char number[13];
    for (char ch = getc(f); 1; ch = getc(f)) {
        if(ch == '-')
            trigger = 1;
        if(ch == ',' || ch == '\n' || ch == EOF){
            m[temp] = atoi(number);
            if(trigger == 1)
                m[temp] = m[temp] * ( -1 );
            trigger = 0;
            temp++;
            memset(number,0,strlen(number));
            count = 0;
            if(ch == EOF)
                return;
        }
        if(ch != ' ' && ch != ',' && ch != '\n' && ch != '-'){
            number[count]= ch;
            count++;
        }
    }
}

void input_check(int args){
    if (args != 3) { // checking number of arguments
        if (args > 3) {
            printf("Error! Too many arguments");
            exit(EXIT_FAILURE);
        } else {
            printf("Error! Not enough arguments");
            exit(EXIT_FAILURE);
        }
    }
    /*if(sargs[2] != '1' || sargs[2] != '2'){
        printf("Error! Wrong input for choosing sorting");
        exit(EXIT_FAILURE);
    }*/
}

int *array_memory(int aboba){
    return (int*)malloc(aboba * sizeof(int));
}

int rows(FILE *f){
    char ch;
    int b = 0;
    for (ch = getc(f); 1; ch = getc(f)) {
        if(ch==',' || ch == '\n' || ch == EOF)
            b++;
        if(ch == EOF)
            return b;
    }
}

void pseudo_random_generator(char* file_name, int x){
    FILE *file;
    file = fopen( file_name, "w+");
    int a;
    for(int i=0;i<x;i++)
    {
        a=rand()%10000;
        //if(rand()%5 == 0)
            //a*=-1;
        fprintf(file, "%d", a);
        if(rand()%6 == 0)
            fprintf(file, "\n");
        else {
            if(i!=x-1){
                fprintf(file, ",");
            }
        }
    }
    fseek(file, 0, SEEK_SET);
    fclose( file );
}