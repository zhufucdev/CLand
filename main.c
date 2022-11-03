//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    int *p;
    p = a; // p = &a[0];
    for (int i = 0; i < 10; i++) {
        printf("%d ", p + i);
    }
    printf("\n");
    return 0;
}
