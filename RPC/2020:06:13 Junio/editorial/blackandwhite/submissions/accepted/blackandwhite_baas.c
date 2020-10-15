#include <stdio.h>
#define MAX_LEN 24

int main(){
    int n, i, j;
    short colCounts[MAX_LEN];
    short colConsec[MAX_LEN];
    char cur;
    short consec = 0;
    short count = 0;
    scanf("%d\n", &n);
    
    for(i = 0; i < n; i++){
        colCounts[i] = 0;
        colConsec[i] = 0;
    }

    for(i = 0; i < n; i++){
        consec = 0;
        count  = 0;
        for(j = 0; j < n; j++){
            scanf("%c",&cur);
            if(cur == 'W'){
                if(consec == -2 || colConsec[j] == -2){
                    printf("0\n");
                    return 0;
                }
                if(consec >= 0){
                    consec = -1;
                } else {
                    consec--;
                }
                if(colConsec[j] >= 0){
                    colConsec[j] = -1;
                } else {
                    colConsec[j]--;
                }
                count--;
                colCounts[j]--;
            } else {
                if(consec == 2 || colConsec[j] == 2){
                    printf("0\n");
                    return 0;
                }
                if(consec <= 0){
                    consec = 1;
                } else {
                    consec++;
                }
                if(colConsec[j] <= 0){
                    colConsec[j] = 1;
                } else {
                    colConsec[j]++;
                }
                count++;
                colCounts[j]++;
            }
        }
        scanf("%c", &cur); 
        if(count != 0){
            printf("0\n");
            return 0;
        }
    }

    for(i = 0; i < n; i++){
        if(colCounts[i] != 0){
            printf("0\n");
            return 0;
        }
    }

    printf("1\n");
}

