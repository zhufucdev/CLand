//
//  main.c
//  CLand
//
//  Created by 朱拂 on 2022/8/30.
//

#include <stdio.h>

extern char * greetings(char * userName);

int main(int argc, const char * argv[]) {
    printf("Hi, %s!\n", greetings("You"));
    return 0;
}
