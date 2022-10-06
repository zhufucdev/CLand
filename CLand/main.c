//
//  main.c
//  CLand
//
//  Created by 朱拂 on 2022/8/30.
//

#include <stdio.h>

int iterate(int, int, int);

int main(int argc, const char * argv[]) {
    int a, n;
    scanf("%1d%d", &a, &n);
    printf("%d\n", iterate(1, a, n));
    return 0;
}

int iterate(int gen, int a, int n) {
    if (gen > n) {
        return 0;
    } else {
        return iterate(gen + 1, a * 10 + a, n) + a;
    }
}
