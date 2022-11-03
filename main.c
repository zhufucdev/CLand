//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n, s = 0;
    scanf("%d", &n);
    int d[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i] > d[j]) {
                s ++;
            }
        }
    }
    printf("%d\n", s);
    return 0;
}
