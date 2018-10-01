#include "posix_header.h"

int main(){

	printf("%s remove named file" , SEM_NAME1);
	sem_unlink(SEM_NAME1);
	printf("%s remove named file" , SEM_NAME2);
	sem_unlink(SEM_NAME2);
	system("ls -al /dev/shm/sem*");
}
