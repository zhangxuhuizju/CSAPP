#include "csapp.h"
#include <stdio.h>

unsigned int snooze(unsigned int secs) {
    unsigned int rc = sleep(secs);
    printf("slept for %u for %u secs.\n", secs - rc, secs);
    return rc;
}

void handler(int sig) {
    printf("\n");
    return;
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("usage: %s <secs>\n", argv[0]);    
        exit(0);
    }

    if (signal(SIGINT, handler) == SIG_ERR)
        unix_error("signal error!\n");
    
    //当运行到sleep程序的时候，收到一个信号会打断sleep并且立即返回。
    //但是一般收到ctrl+c信号在处理的时候会直接把程序终止了，因此调用handler来把控制权返回给sleep
    snooze(atoi(argv[1]));
    return 0;
}
