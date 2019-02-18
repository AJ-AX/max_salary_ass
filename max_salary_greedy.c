#include "max_salary.h"

// RUN TIME OF ALGORITHMN - N^2
// AT A CERTAIN POINT, C IS UNABLE TO HANDLE THE SIZE OF THE INT USING LONG INT.
// DUE TO THE LARGE SIZE OF THE NUMBER
// THEREFORE, THE TOTAL LENGTH CANNOT BE LARGER THAN A CERTAIN NUMBER.
long max_salary_greedy(int a[], int size){
    
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(is_better(a[i], a[j]) == a[j]){
                SWAP(a[i], a[j]);
            }
        }
    }

    int final_len = 0;
    for(int i = 0; i < size; i++){
        final_len += len(a[i]);
    }

    //printf("%d", final_len);
    char *final = calloc(final_len, sizeof(char));
    for(int i = 0; i < size; i++){
        char *part = malloc(len(a[i]) + 1);
        snprintf(part, len(a[i]) + 1, "%d", a[i]);
        strcat(final, part);
        free(part);
    }
    //printf("\n%s", final);

    char *ptr;
    long final_l = strtol(final, &ptr, 10);

    //printf("\n%ld", final_l);

    return final_l;
}

int main(){

    int arr[9] = {121, 1, 3, 4, 5, 628, 87, 98, 999};
    long z = max_salary_greedy(arr, 9);

    printf("%ld", z);

    return 0;
}