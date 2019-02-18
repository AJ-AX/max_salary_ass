#include "max_salary.h"

long best_arr = 0;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

// Generating permutation using Heap Algorithm 
// Alg. Run Time: O(N-1!)
void heap_permutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then do something with the obtained permutation   
    if (size == 1) 
    { 
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        //print_array(a, n);
        int final_len = 0;
        for(int i = 0; i < n; i++){
            final_len += len(a[i]);
            //printf("%d ", a[i]);
        }
        char *final = calloc(final_len + 1, sizeof(char));
        for(int i = 0; i < n; i++){
            char *part = malloc(len(a[i]) + 1);
            snprintf(part, len(a[i]) + 1, "%d", a[i]);
            strcat(final, part);
            free(part);
        }
        //printf(" Final Permutation: %s\n", final);
        char *ptr;
        long final_l = strtol(final, &ptr, 10);

        if(final_l > best_arr){best_arr = final_l;}
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a,size-1,n); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		}			
    } 
} 
  
// Code to test permutations
/*int main() { 
    //int a[] = {1, 2, 3, 43, 71, 96, 521, 762, 815}; 
    int a[] = {121, 1, 3, 4, 5, 628, 87, 98, 999};
    int n = sizeof a/sizeof a[0]; 
    heap_permutation(a, n, n); 

    printf("\nBest Array: %ld\n", best_arr);
    return 0; 
}*/