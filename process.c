// printf
#include <stdio.h>
// pid_t
#include <sys/types.h>
// waitpid
#include <sys/wait.h>
// fork
#include <unistd.h>
// exit
#include <stdlib.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int main(void)
{
    printf("start\n");
    sleep(10);
    pid_t pid = fork();
    printf("fork pid:%d\n",pid);
    sleep(10);
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("child pid:%d\n", pid);
    }
    else {
        int status;
        printf("main wait start pid:%d\n", pid);
        (void)waitpid(pid, &status, 0);
        printf("main wait end pid:%d\n", pid);
    }
    sleep(10);
    printf("exit pid:%d\n", pid);
    return EXIT_SUCCESS;
}
