#include "posix_header.h"

int main(){
	int sval1, sval2;
	sem_t *sem_named1, *sem_named2;
	if((sem_named1=sem_open(SEM_NAME1,0))==SEM_FAILED)DIE("sem_open1");
	if((sem_named2=sem_open(SEM_NAME2,0))==SEM_FAILED)DIE("sem_open2");

	sem_getvalue(sam_named1, &sval1); sem_getvalue(sam_named2, &sval2);
	printf("return semaphore \n");
	sem_post(sem_named1); sem_post(sem_named2);
	sem_getvalue(sem_named1, &sval1); sem_getvalue(sem_named2, &sval2);
	printf("semaphore %s's value = %d \n", SEM_NAME1, sval1);
	printf("semaphore %s's value = %d \n", SEM_NAME2, sval2);
	sem_close(sem_named1); sem_close(sem_named2);

}
