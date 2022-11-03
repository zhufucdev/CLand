//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    int (**matrix) = (int**) malloc(sizeof(int) * n * n);
    for (int y = 0; y < n; y++) {
        *(matrix + y) = (int*) malloc(sizeof(int) * n);
        for (int x = 0; x < n; x++) {
            scanf("%d", *(matrix + y) + x);
        }
    }

    for (int x = 1; x < n; x++) {
        for (int y = 0; y < x; y++) {
            int t = *(*(matrix + y) + x);
            *(*(matrix + y) + x) = *(*(matrix + x) + y);
            *(*(matrix + x) + y) = t;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++)
            printf("%d ", *(*(matrix + y) + x));
        printf("\b\n");
    }
    return 0;
}
