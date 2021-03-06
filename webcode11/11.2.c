#include "csapp.h"
#include <errno.h>
#include "csapp.c"
//#include <pthread.h>


int main(int argc, char **argv)
{
    struct in_addr inaddr;
    uint32_t add;
    char buf[MAXBUF];
    if (argc != 2) {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0);
    }
    sscanf(argv[1], "%x", &add);
    inaddr.s_addr = htonl(add);
    if(!inet_ntop(AF_INET, &inaddr, buf, MAXBUF))
        unix_error("inet_ntop");
    printf("%s\n", buf);
    exit(0);
}