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
     //define the strucutures 
    struct arg_int *portz;
    portz = arg_int1(NULL,"port","<n>","PORT TARGET");
    struct arg_str *host;
    host = arg_str1("h","host","<n>","host target");
    struct arg_lit *help;
    help = arg_lit1(NULL,"help","help option");
    struct arg_str *mac_addr_s;
    mac_addr_s = arg_str1("s","mac_addr_s","<n>","mac addr source");
    struct arg_str *mac_addr_d;
    mac_addr_d = arg_str1("d","mac_addr_d","<n>","mac addr destination");
    struct arg_end *end = arg_end(20); //special type holds the cmdline args error and marks end of array to hold the elements
    void *argvtable[]= {host,portz,help,mac_addr_s,mac_addr_d,end};
    //start parsing
    int start_parse = arg_parse(argc,argv,argvtable);
    if(help->count == 1){
        arg_print_glossary(stdout,argvtable,NULL);
    }
    //printf("%s\n",host->sval[0]);
    //printf("%d\n",portz->ival[0]);
    //free alocated memory
    arg_freetable(argvtable,sizeof(argvtable)/sizeof(argvtable[0]));
    int sock_fd;
    int port = portz->ival[0];
    printf("%d",port);
    struct sockaddr_in current_socket;
    struct hostnent *hostid;
    sock_fd = socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
    //case if no argument supplied
    //help(argc,argv);
    //else any arguments supplied
    parse(argc,argv);
    return 0;
}
