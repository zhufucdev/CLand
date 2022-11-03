//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>

int iterate(int day, int amount);

int loop(void);

int main(int argc, const char * argv[]) {
    int x = iterate(9, 1);
    int y = loop();
    if (x == y)
        printf("%d\n", x);
    else
        printf("inconsistent results: %d and %d", x, y);
    return 0;
}

int loop(void) {
    int amount = 1;
    for (int i = 0; i < 9; i++) {
        amount = (amount + 1) * 2;
    }
    return amount;
}

int iterate(int day, int amount) {
    return day == 0 ? amount : iterate(day - 1, (amount + 1) * 2);
}

