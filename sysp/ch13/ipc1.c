#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(){
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",0));
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",1));
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",2));
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",0));
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",1));
	printf("%s key = %d\n", "/etc/passwd", ftok("/etc/passwd",2));
	printf("%s key = %d\n", "/etc/pas", ftok("/etc/pas",1));
	printf("%s key = %d\n", ".", ftok(".",1));
	printf("%s key = %d\n", "..", ftok("..",1));


}
