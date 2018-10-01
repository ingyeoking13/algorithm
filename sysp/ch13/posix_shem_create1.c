#include "posix_header.h"

int main(){

	sem_t *sem_named1, *sem_named2;
	if ((sem_named1=sem_open(SEM_NAME1, O_CREAT, 0644, 1)) == SEM_FAILED)DIE("sem_open1");
	printf("create semaphore %s \n", SEM_NAME1);
	if((sem_named2=sem_open(SEM_NAME2, O_CREAT, 0644, 2)) == SEM_FAILED)DIE("sem_open2");
	printf("create semaphore %s \n", SEM_NAME2);

	int sval1, sval2;
	sem_getvalue(sem_named1, &sval1);
	sem_getvalue(sem_named2, &sval2);
	printf("semaphore %s's value = %d \n", SEM_NAMED1, sval1);
	printf("semaphore %s's value = %d \n", SEM_NAMED2, sval2);
	printf("create named semaphore file \n");
	system("ls -al /dev/shm/sem*");
	sem_close(sem_named1);
	sem_close(sem_named2);
}
