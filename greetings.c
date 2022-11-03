//
//  greetings.c
//  CLand
//
//  Created by 朱拂 on 2022/9/14.
//

#include "greetings.h"

char* greetings(char* userName) {
    char* r;
    asprintf(&r, "dear %s", userName);
    return r;
}
