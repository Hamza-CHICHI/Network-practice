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
    struct sockaddr_in monAddresse;

    hote = gethostbyname(nomHote);

    if( hote == NULL )
    {
        fprintf(stderr, "Nom d'hote %s inconnue.\n", nomHote);
        exit(EXIT_FAILURE);
    }
    
    memcpy(&(monAddresse.sin_addr), hote->h_addr_list[0], sizeof(u_long));
    //monAddresse.sin_addr = *((struct in_addr*)hote->h_addr_list[0]);
    
    printf("%s ------- %s\n", nomHote, inet_ntoa((monAddresse.sin_addr)));
    return 0;
}
