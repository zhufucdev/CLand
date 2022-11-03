//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>
#include <stdlib.h>
#define CACHE_SIZE 10

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

void test(int n, char **arr) {
    int failed = 0;
    for (int y = 0; y < factorial(n); y ++) {
        for (int x = 0; x < y; x++) {
            int equals = 0;
            for (int i = 0; i < n; i++) {
                if (arr[y][i] == arr[x][i]) {
                    equals ++;
                }
            }
            if (equals == n) {
                printf("Test %d failed.\n", y);
                failed = 1;
            }
        }
    }
    if (!failed) {
        printf("Test succeeded.\n");
    }
}

int main(int argc, const char * argv[]) {
    f_cache = (int*) calloc(CACHE_SIZE, sizeof(int));

    int n;
    scanf("%d", &n);

    char **arr = arrange(n);
    for (int i = 0; i < factorial(n); i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (int) arr[i][j] + 1);
        }
        printf("\n");
    }
//    test(n, arr);
    free(arr);
    return 0;
}

