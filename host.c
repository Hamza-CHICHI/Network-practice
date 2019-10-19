#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
int main(){
    struct hostent *hote = NULL;
    const char *nomHote = "www.ensias.ma";
    struct in_addr ip;
    

    hote = gethostbyname(nomHote);

    if( hote == NULL )
    {
        fprintf(stderr, "Nom d'hote %s inconnue.\n", nomHote);
        exit(EXIT_FAILURE);
    }
    
    memcpy(&(ip.s_addr), hote->h_addr_list[0], sizeof(u_long));
    
    
    printf("%s ------- %s\n", nomHote, inet_ntoa(ip) );
    
    return 0;
}
