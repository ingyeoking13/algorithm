#include <stdio.h>
#define CELL_MAX 512 // data size upper limits(2^9)x(2^9)
#define STR_MAX 300

void compressor(int row, int ool, int cellSize);
void decompressor (int row, int col, int cellSize);
char table[CELL_MAX][CELL_MAX], comp[STR_MAX];
int comp_index, size;

int main(int agrc, char *argv[]) {
	char cmd, dummy; int i, j;
	printf("type command, compression for 'c' and decompression for 'd': ");
	scanf("%s", &cmd);
	printf("cell size: ");
	scanf("%d", &size);

	comp_index = 0;
	if (cmd == 'c') {
		for (i = 0; i < size; i++) scanf("%s", table[i]);
		compressor(0, 0, size);
		printf("%s\n", comp);
	}
	else if (cmd == 'd') {
		scanf("%s", comp);
		decompressor(0, 0, size);
		for (i = 0; i < size; i++) {
			printf("%s\n", table[i]);
		}
	}
	return 0;
}

void compressor(int row, int col, int s) {
	if (s==1){
		comp[comp_index++]=table[row][col]; comp[comp_index++]=table[row][col+1];
		comp[comp_index++]=table[row+1][col+1]; comp[comp_index++]=table[row+1][col];
	}
	else{
		int chk=1;
		char now=table[row][col];
		for (int i=0; i<s; i++){
			for (int j=0; j<s; j++){
				if(now != table[row+i][col+j]) chk=0;
			}
		}
		if (chk){
			comp[comp_index++]='1';
			comp[comp_index++]=now;
		}
		else{
			comp[comp_index++]='0';
			if (s/2==1) compressor(row, col, s/2);
			else {
			  compressor(row, col, s/2);
				compressor(row, col+s/2, s/2);
				compressor(row+s/2, col+s/2, s/2);
				compressor(row+s/2, col, s/2);
			}
		}
	}
}

void decompressor(int row, int col, int s){
	if(s==1){
		table[row][col]=comp[comp_index++]; table[row][col+1]=comp[comp_index++];
		table[row+1][col+1]=comp[comp_index++]; table[row+1][col]=comp[comp_index++];
	}
	else{
		if(comp[comp_index]=='1'){
			comp_index++;
			for (int i=0; i<s; i++){
				for (int j=0; j<s; j++){
					table[row+i][col+j]=comp[comp_index];
				}
			}
			comp_index++;
		}
		else if (comp[comp_index++]=='0'){
			if (s/2==1) decompressor(row, col, s/2);
			else{
				decompressor(row, col, s/2);
				decompressor(row, col+s/2, s/2);
				decompressor(row+s/2, col+s/2, s/2);
				decompressor(row+s/2, col, s/2);
			}
		}
	}
}
