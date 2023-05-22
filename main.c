#include "main.h"

int main(int args, char *sargs[]){
    input_check(args);
    pseudo_random_generator(sargs[1], random_quantity);
    char *file_name = sargs[1];
    FILE *f = fopen(file_name, "r");
    int *m;
    fseek(f, 0, SEEK_SET);
    int a = rows(f);
    fseek(f, 0, SEEK_SET);
    m=array_memory(a);
    fseek(f, 0, SEEK_SET);
    input_data(m,f);
    fclose(f);
    free(f);
    /*for(int i = 0; i < a; i++){
        //printf("%d ",m[i]);
    }*/
    if(atoi(sargs[2]) == 1){
        printf("Shaker sorting system:\n");
        shakerSort(m, a);
        /*for(int i = 0; i < a; i++){
            //printf("%d ",m[i]);
        }*/
    }
    else{
        printf("Bead (Gravity) sorting system:\n");
        int min;
        for(int i = 0; i < a; i++){
            if(min>m[i])
                min = m[i];
        }
        if(min < 0){
            for(int i = 0; i < a; i++){
                m[i]+=abs(min);
            }
            double time_spent = 0.0;
            clock_t begin = clock();
            bead_sort(m,a);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("The elapsed time is %f seconds\n", time_spent);
            for(int i = 0; i < a; i++){
                m[i]-=abs(min);
            }
        }
        else {
            double time_spent = 0.0;
            clock_t begin = clock();
            bead_sort(m,a);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("The elapsed time is %f seconds\n", time_spent);
        }
        for(int i = 0; i < a; i++){
            //printf("%d ",m[i]);
        }
    }
    free(m);
    return 0;
}