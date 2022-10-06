//
//  main.c
//  CLand
//
//  Created by 朱拂 on 2022/8/30.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a, n, i, num_produced, sum;
    scanf("%1d%d", &a, &n);
    for (num_produced = a, sum = 0, i = 0; i < n; i++) {
        sum += num_produced;
        num_produced = num_produced * 10 + a;
    }
    printf("%d\n", sum);
    return 0;
}
