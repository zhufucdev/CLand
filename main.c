//
// Created by 朱拂 on 2022/11/3.
//

#include <stdio.h>
#include <stdlib.h>

void limit(char ** p, int n) {
    int stars = 0;
    char *x = *p;
    char *t = x;
    while (*t == '*') {
        stars ++;
        t ++;
    }
    int removal = stars - n;
    if (removal > 0) {
        char * o = x;
        x += removal - 1;
        *x = '\0';
        x ++;
        free(o);
        *p = x;
    }
}

int main(int argc, const char * argv[]) {
    char * c = (char *) malloc(81);
    int n;
    scanf("%s %d", c, &n);

    limit(&c, n);
    printf("%s\n", c);
    return 0;
}
