#include "max_salary.h"

int len(int x){
    return snprintf(NULL, 0, "%d", x);
}

int is_better(int n, int x){
    int len_n = len(n);
    int len_x = len(x);

    // Convert int to string for indexing
    char *str_n = malloc(len_n + 1);
    char *str_x = malloc(len_x + 1);

    snprintf(str_n, len_n + 1, "%d", n);
    snprintf(str_x, len_x + 1, "%d", x);

    // First Case - Integers are Equal
    if(strcmp(str_n, str_x) == 0){
        return x;
    }

    // Second Case - Integers are the Same Length but different
    else if(len_n == len_x && strcmp(str_n, str_x) != 0){
        for(int i = 0; i < len_n; i++){
            if( (*(str_n + i) - '0') > (*(str_x + i) - '0') ){
                free(str_n);
                free(str_x);
                return n;
            }
            else if( (*(str_n + i) - '0') < (*(str_x + i) - '0') ){
                free(str_n);
                free(str_x);
                return x;
            }
        }
    }

    // Third/Fourth Case - One string is larger than the other.
    // All comments for this section are valid for the other.
    // I should have used one master variable and then a comparator rather than two.
    // I am too lazy to fix it.

    else if(len_n > len_x){

        // Create Strings of Smaller Size to Compare
        char *ln_n = malloc(len_x + 1);
        char *ln_x = malloc(len_x + 1);

        strcpy(ln_n, str_n);
        strcpy(ln_x, str_x);

        // Cut larger string
        *(ln_n + len_x) = '\0';

        // If the remaining strings are equal, compare the remainder of the longer string with the first character of the shorter string.
        if(strcmp(ln_n, ln_x) == 0){
            int len_d = len_n - len_x;
            for(int i = 0; i < len_d; i++){
                //printf("%c\n", *(str_n+len_x+i));
                if((*(str_n+len_x+i) - '0') > (*(ln_x) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return n;
                }
            }
            free(str_n);
            free(str_x);
            free(ln_n);
            free(ln_x);
            return x;
        }
        // Otherwise, just loop over the string to see which is larger.
        else{
            for(int i = 0; i < len_x; i++){
                if( (*(ln_n + i) - '0') > (*(ln_x + i) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return n;
                }
                else if ( (*(ln_n + i) - '0') < (*(ln_x + i) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return x;
                }
            }
        }
    }

    // Lazy Copy/Paste
    else if(len_x > len_n){
        char *ln_n = malloc(len_n + 1);
        char *ln_x = malloc(len_n + 1);

        strcpy(ln_n, str_n);
        strcpy(ln_x, str_x);

        *(ln_x + len_n) = '\0';

        if(strcmp(ln_x, ln_n) == 0){
            int len_d = len_x - len_n;
            for(int i = 0; i < len_d; i++){
                if((*(str_x+len_n+i) - '0') > (*(ln_n) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return x;
                }
            }
            free(str_n);
            free(str_x);
            free(ln_n);
            free(ln_x);
            return n;
        }
        else{
            for(int i = 0; i < len_n; i++){
                if( (*(ln_x + i) - '0') > (*(ln_n + i) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return x;
                }
                else if( (*(ln_x + i) - '0') < (*(ln_n + i) - '0') ){
                    free(str_n);
                    free(str_x);
                    free(ln_n);
                    free(ln_x);
                    return n;
                }
            }
        }
    }

    //FUNCTION SHOULD NEVER REACH HERE
    return 0;
}

/*int main(){
    int x = 9810182;
    int z = 911238123;

    int bet = is_better(x, z);

    printf("%d\n", bet);

    return 0;
}*/