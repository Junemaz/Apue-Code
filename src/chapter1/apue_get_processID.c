#include "apue.h"

int main(void) {
    printf("this process's id is %ld\n", (long)getpid());
    exit(0);
}