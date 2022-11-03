//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#define CACHE_SIZE 10

int reversed_count(int n, char d[]) {
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

int *f_cache;

int factorial(int x) {
    if (f_cache[x]) {
        return f_cache[x];
    }

    int s = 1;
    for (int i = 2; i <= x; i++) {
        s *= i;
    }

    f_cache[x] = s;
    return s;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void fix(int i, int n, char **arr, char *changes) {
    for (int j = 0; j < n; j++) {
        int period = factorial(n - j - 1);
        if (i % period == 0) {
            char choice = 0;
            for (int k = 0; k < n; k++) {
                int contains = 0;
                for (int l = 0; l < j; l++) {
                    if (k == arr[i][l]) {
                        contains = 1;
                        break;
                    }
                }
                if (!contains) {
                    int previous = factorial(n - j);
                    for (int l = max(0, i / previous * previous); l < i; l += period) {
                        if (k == arr[l][j]) {
                            contains = 1;
                            break;
                        }
                    }
                }
                if (!contains) {
                    choice = k;
                    break;
                }
            }
            arr[i][j] = choice;
            changes[j] ++;
        } else {
            arr[i][j] = arr[i - 1][j];
        }
    }
}

char **arrange(int n) {
    int rows = factorial(n);
    char **result = (char**) calloc(rows, sizeof(*result));
    char *changes = (char*) calloc(rows, sizeof(char));
    for (int i = 0; i < rows; i++) {
        result[i] = (char*) calloc(n, sizeof(char) * n);
        fix(i, n, result, changes);
    }
    free(changes);

    return result;
}


int main(int argc, const char * argv[]) {
    f_cache = (int*) calloc(CACHE_SIZE, sizeof(int));

    int n;
    scanf("%d", &n);
    float det[n][n];
    for (int i = 0; i < n * n; i++) {
        int x;
        scanf("%d", &x);
        det[i / n][i % n] = x;
    }

    float s = 0;
    char** arr = arrange(n);
    int rows = factorial(n);
    for (int y = 0; y < rows; y ++) {
        char *arrange = arr[y];
        float product = 1.0F;
        for (int x = 0; x < n; x++) {
            int row = arrange[x];
            product *= det[x][row];
            printf("a%d%d", x + 1, row + 1);
            if (x < n - 1) {
                printf(" * ");
            }
        }
        if (reversed_count(n, arrange) % 2 == 1) {
            product *= -1;
        }
        s += product;
        printf(" = %f", product);
        if (y < rows - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    printf("sum = %f\n", s);
    free(f_cache);
    free(arr);
    return 0;
}
