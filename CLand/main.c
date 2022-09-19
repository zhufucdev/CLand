//
//  main.c
//  CLand
//
//  Created by 朱拂 on 2022/8/30.
//

#include <stdio.h>
#include <stdlib.h>

int factorial(int x) {
    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }
    return s;
}

int reversed_count(int n, int d[]) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j ++) {
            if (d[i] > d[j]) {
                s ++;
            }
        }
    }
    return s;
}

int** arrange(int n) {
    int size = factorial(n);
    int **arranges = (int**) malloc(size);
    for (int i = 0; i < size; i++) {
        int arrange[n];
        void fix(int, int, int, int[]);
        fix(i, n, 0, arrange);
        arranges[i] = arrange;
    }
    
    return arranges;
}

void fix(int index, int n, int count, int fixed[]) {
    
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    float det[n][n];
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        det[i / n][i % n] = x;
    }
    
    float s = 0;
    int** arranges = arrange(n);
    for (int y = 0; y < n; y ++) {
        int *arrange = *arranges + y;
        float product = 1.0F;
        for (int x = 0; x < n; x++) {
            int row = *arrange + x;
            product *= det[x][row];
            printf("a%d%d", x, row);
            if (x < n - 1) {
                printf(" * ");
            }
        }
        if (reversed_count(n, arrange) % 2 == 1) {
            product *= -1;
        }
        s += product;
        printf(" = %f", product);
        if (y < n - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
    
    printf("sum = %f\n", s);
    return 0;
}
