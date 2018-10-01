#include <stdio.h>

int main(){
	int ans=0;

	for (int i=0; i<10; i++) ans++;
	for (int i=0; i<9; i++) ans++;
	for (int i=0; i<8; i++) ans++;
	for (int i=0; i<7; i++) ans++;

	printf("%d\n", ans);
}
