#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include "ipheader.h"
#include <string.h>
#include <linux/tcp.h>
#include "argtable2.h"

/*define constants*/
#define packetsize 1500

int help(int arguments,char *argumentz[]){
    if(arguments < 2){
        printf("usage:%s [options]\n",(char*)argumentz[0]);
    }
    return 0;
}


int main(int argc,char *argv[])
{
    int sock_fd;
    int port;
    struct sockaddr_in current_socket;
    struct hostnent *hostid;
    sock_fd = socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
    help(argc,argv);
  //  struct arg_int *portz;
   // portz = arg_int1(NULL,"port","<n>","PORT TARGET");
    struct arg_str *host;
    host = arg_str1("h","host","<n>","host target");
    struct arg_end *end = arg_end(20);
    void *argvtable[]= {host,end};
    int start_parse = arg_parse(argc,argv,argvtable);
    printf("%s",host->sval[0]);
    //printf("%d",s->count);
    return 0;
}
