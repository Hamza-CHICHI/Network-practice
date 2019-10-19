#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>		// types sockets de base
#include <sys/types.h> 		// types de base
#include <netinet/in.h>		// struct sockaddr_in
#include <arpa/inet.h> 		// int inet_aton(char *cp, struct in_addr *inp)
#include <netdb.h> 			// struct hostent *gethostbyname(const char *name)



int main(int argc, char const *argv[])
{
	struct hostent *hote = NULL;
	char host_name[256] ;
	printf("ENTER A WEBSITE : \n");
	scanf("%[^\n]s",host_name);
	

	hote = gethostbyname(host_name);

	if (hote == NULL){ printf("unknown host name\n"); exit(EXIT_FAILURE);}


	printf("\n\n---------%s\n",host_name);

	printf("Official name : \n\t%s\n",hote -> h_name );

	printf("Aliases of %s\n",host_name );
	char **aliases ;
	aliases = hote -> h_aliases;
	while ((*aliases) != NULL)
	{
		printf("\t%s\n",*(aliases++));
	}

	printf("IP adress of %s :\n",host_name);


	struct in_addr **ip_address = (struct in_addr **)hote -> h_addr_list;
	while( *(ip_address)!= NULL )
	{
		printf("\t%s\n",inet_ntoa(**ip_address) );
		ip_address++;
	}
	// struct in_addr **ip_address;
	// for (ip_address = (struct in_addr **)hote -> h_addr_list; *(ip_address)!= NULL; ip_address++)
	// {
	// 	printf("\t%s\n",inet_ntoa(**ip_address) );
	// }

	return 0;
}