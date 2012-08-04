#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>

#define oops(m,x)  { perror(m);exit(x);}

int make_dgram_client_socket();
int make_internet_address(char *,int, struct sockaddr_in *);

int main(int argc, char *argv[])
{
    int sock;
    char* msg;
    struct sockaddr_in saddr;

    if (argc != 4)
    {
	fprintf(stderr, "usage: dgsend host port 'message'\n");
	exit(1);
    }
    msg = argv[3];

    if ((sock = make_dgram_client_socket()) == -1)
    {
	oops("cannot make socket", 2);
    }

    if (make_internet_address(argv[1], atoi(argv[2]), &saddr) == -1)
    {
	oops("make addr", 4);
    }

    if (sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&saddr, sizeof(saddr)) == -1)
    {
	oops("sendto failed", 3);
    }
    return 0;
}
