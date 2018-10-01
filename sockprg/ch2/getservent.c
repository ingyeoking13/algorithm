#include <stdio.h>
#include <netdb.h>

int main(){
	struct servent *p;

	while(1){
		if ( !(p = getservent())) break;

		printf("%s\t %d/%s\t", p->s_name, ntohs(p->s_port), p->s_proto);
		for (int i=0; p->s_aliases[i] ; i++)
			printf("%s", p->s_aliases[i]);
		printf("\n");

	}

}
