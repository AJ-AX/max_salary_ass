#include "max_salary.h"

int main(){

    int tests = 10;
    int arr_length = 9;
    int max_number = 100;

    clock_t t;
    double greedy_time_used;
    double naive_time_used;

    double avg_greed = 0;
    double avg_naive = 0;

    srand(time(NULL));
    for(int i = 0; i < tests; i++){
        best_arr = 0;
        int arr[arr_length];
        for(int i = 0; i < arr_length; i++){
            arr[i] = (rand() % max_number) + 1;
        }
        
        t = clock();
        long msg = max_salary_greedy(arr, arr_length);
        t = clock()-t;
        greedy_time_used = ((double)t)/CLOCKS_PER_SEC;
        avg_greed += greedy_time_used;

        t = clock();
        heap_permutation(arr, arr_length, arr_length);
        t = clock()-t;
        naive_time_used = clock()-t;
        avg_naive += naive_time_used;

        printf("Salary Computed by Greedy Algorithmn: %ld\n", msg);
        printf("Time Taken by Greedy Algorithm: %lf\n", greedy_time_used);
        printf("Salary Computed by Naive Algorithmn: %ld\n", best_arr);
        printf("Time Taken by Naive Algorithmn: %lf\n", naive_time_used);
        if(msg == best_arr){
            printf("Salaries Match.\n\n");
        }else{
            printf("Salaries do not Match.\n\n");
        }
    }

    printf("Average Time of Greedy Algorithmn: %lf\n", avg_greed/tests);
    printf("Average Time of Naive Algorithmn: %lf\n", avg_naive/tests);
    return 0;
}