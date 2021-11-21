#include "apue.h"
#include <sys/wait.h>

int main(void) {
    char buf[MAXLINE]; //from apue.h
    pid_t pid;
    int status;
    printf("%% "); //print promote (printf requires %% to print %)
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }
        if ((pid = fork()) < 0) {
            err_sys("fock error");
        } else if (pid == 0) {
            execlp(buf , buf, (char*)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        //parent
        if ((pid == waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}