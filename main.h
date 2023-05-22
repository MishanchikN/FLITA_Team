#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>

#define random_quantity 10000 //quantity of numbers in generated txt file

void shakerSort(int *mass, int count);

void bead_sort(int *a, int len);

void input_data(int *m, FILE *f);
void input_check(int args);
int *array_memory(int aboba);
int rows(FILE *f);
void pseudo_random_generator(char* file_name, int x);