/*Can create separate header file (.h) for all headers' structure*/
/* The IP header's structure*/
#include <netinet/ip.h>
#include <linux/tcp.h>
#include <linux/if_ether.h>
#include <linux/types.h>
struct ethhddr{
    unsigned char h_dest[ETH_ALEN]; /*eth dest*/
    unsigned char h_source[ETH_ALEN]; /*eth source*/
    unsigned short h_proto;
};
struct ipheader {
 unsigned char      iph_ihl:5, iph_ver:4;
 unsigned char      iph_tos; /*priority of que*/
 unsigned short int iph_len; /*size of header*/
 unsigned short int iph_ident; /*tipe of class a:b:c?*/
 unsigned char      iph_flag; /*state of the header*/
 unsigned short int iph_offset; /*distace between host and endpoint*/
 unsigned char      iph_ttl; /*time to live packet*/
 unsigned char      iph_protocol; /*Tcp mainly*/
 unsigned short int iph_chksum; /*check to see if all packets have been send*/
 unsigned int       iph_sourceip; /*source*/
 unsigned int       iph_destip; /*dest*/
};
/*
struct tcphdr{
    unsigned int source; //source
    unsigned int dest; //destination
    unsigned int seq; //sequences send
    unsigned int ack_seq; //ackuire sequence how much was ack,decide how much to send
    unsigned int window; //ack for tcp
    unsigned int check; //checksum
    unsigned int urg_ptr;   
}
*/