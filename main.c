//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>

int power(int x, int n);

int main(int argc, const char * argv[]) {
    printf("2^12 = %d\n", power(2, 12));
    return 0;
}

int power(int x, int n) {
    if (!n) {
        return 1;
    }
    return x * power(x, n - 1);
}
