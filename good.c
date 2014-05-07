#include "stdlib.h"
#include "stdio.h"

void clearMat(int *mat, int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++)
            mat[i*2000+j] = 0;
    }

}
int max(int a, int b) {
    return a > b? a: b;
}
int maxCost(int *cost, int *price, int n, int S) {
    clearMat(cost, n+1, S+1);

    int i;
    int j;
    for(i = 1; i < n+1; i++) {
        for(j = 1; j < S+1; j++) {
            if(price[i-1] > j) {
                cost[i*2000+j] = cost[(i-1)*2000+j]; 
            } else {
                cost[i*2000+j] = max(cost[(i-1)*2000+j], price[i-1]+cost[(i-1)*2000+j-price[i-1]]);
            }
            //printf("test i j %d %d %d %d\n", i, j, price[i], cost[(i-1)*2000+j]);
        }
    }
    for(i = 0; i < n+1; i++) {
        for(j=0; j < S+1; j++) {
            printf("%d ", cost[i*2000+j]);
        }
        printf("\n");
    }
    return cost[n*2000+S];
}

int main() {
    int S;
    int n;
    int *price = malloc(sizeof(int)*2000);
    int *cost = malloc(sizeof(int)*2001*2001);
    scanf("%d", &S);
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", price+i);
    }

    int res = maxCost(cost, price, n, S);
    printf("%d\n", res); 
}
