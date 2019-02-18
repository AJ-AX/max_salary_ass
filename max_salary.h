#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void heap_permutation(int a[], int size, int n) ;

int len(int x);
int is_better(int n, int x);

long max_salary_greedy(int a[], int size);

long best_arr;

#endif