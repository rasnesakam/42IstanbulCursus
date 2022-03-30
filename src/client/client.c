#include "client.h"

int main(int argc, char **argv){
    int     pid;
    char    *message;

    if (argc >= 3 )
    {
        pid = ft_atoi(argv[1]);
        message = argv[2];
        ft_sendmsg(pid,message);
    }
    
    return(0);
}