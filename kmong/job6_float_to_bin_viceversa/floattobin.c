// this subject is very interesting ...
// float  to binary  and binary to float conversion
// you can have word E <--- 2E5 means 2* 10^5 , 2E-5 means 2 * (10^-5)
#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <unistd.h>

float absd(float a){ if (a<0) return -a; return a;}

union floating{ //using union, to offer two way access
	struct {   //we offer a way "bit-field structure" futher informations are in link below
		unsigned int mant : 23;  // https://dojang.io/mod/page/view.php?id=472
		unsigned int exp  : 8;   
		unsigned int sign : 1;
	}bits ;
	float fnum;   //with this variable, we store the real float numbers
};

float getfloat(char* s, int len, int sign, int coef){

	float tmp;
	int point=-1, num=0;

	for (int i=(sign==1?0:1); i<len; i++){
		if (s[i] =='.') point++;   //check if we have point in input string
		else {
			num *= 10;
			num += (s[i]-'0');
			if (point>=0) point++;  //if we have point then cnt it to find num that  10^(-num)
		}
	}

	if(point>=0) tmp = num*pow(10,-point)*pow(10, coef);
	else tmp = num*pow(10, coef); 
	tmp*=sign;
	return tmp;
}

void convtE(float b_to_f){ // E 로 양식 변환 출력
		int cnt=0;
		if (b_to_f>=1e-6 ) { // if b_to_f smaller than 10^-6....
			while(absd(b_to_f)>=10 || absd(b_to_f)<1) {
				if ( absd(b_to_f)<1 ) b_to_f*=10, cnt--;
				else b_to_f/=10, cnt++;
			}
		}
		if(cnt) printf("%fE%d\n",b_to_f, cnt);
		else printf("%f\n", b_to_f);
}

void ftb(){ // make binary number to float number xxxx xxxx xxxx... input type
		char bin[8][5]; //store binary num
		for (int i=0; i<8; i++) scanf("%s",bin[i]);

		int sign = bin[0][0]=='1'?-1:1;
		int X = (1<<9)-1; //IEEE 754  says... 127...

		int Exp=0;

		for (int i=0; i<2; i++){
			for (int j=0; j<4; j++){
				if (i==0 && j==0) continue; //because b[0][0] store sign
				Exp *= 2;
				Exp += (bin[i][j]-'0');
			}
		}
		Exp *= 2; 
		Exp += (bin[2][0]-'0'); //because bin[2][0] is 9th bit from front. it is Expbit.

		//and then we calculate fraction bits... to get mantessa
		float Mant = 0;
		for (int i=2; i<8; i++){
			for (int j=0; j<4; j++){
				if (i==2 && j==0) continue; 
				float tmp=bin[i][j]-'0';			//if we have bits in fractions part...
				if(tmp) tmp = pow(2, -(i-2)*4-j); //it has 2^(-pos) value...
				Mant+=tmp;                       //then add to mantessa part
			}
		}

		// (-1)^s + (1+Mant)*2^e 
		float b_to_f= sign*(1+Mant)*pow(2 ,Exp-127);
		printf("%d * (1+%f) * 2^(%d):\n", sign, Mant, Exp-127);
		convtE(b_to_f);  //print with E
}


void btf(){ //make float number to binary number .... real hard work

	char s[16]; scanf("%s", s); // your input should be less than 15 length string
	int n = strlen(s);

	int chk=-1;
	for (int i=0; i<n; i++) {
		if (s[i] == 'E') chk=i; // if we have scientific notation
	}

	float num=0, coef=0, tmp; // tmp will store last float
	int sign=1, coefsign=1; //sign for num.

	if (chk != -1){ // if we have E notation
		if(s[0] =='-') sign=-1;
		if(s[chk+1] == '-') coefsign=-1;

		for (int i=(coefsign==1?chk+1:chk+2); i<n; i++){ // chk coef number. 
			coef*= 10;
			coef+= (s[i]-'0');
		}

		coef*= coefsign;
		tmp = getfloat(s, chk, sign, coef);

	}
	else {  // if we have no E  word
		if (s[0] == '-' )  sign=-1;
		tmp = getfloat(s, n, sign,0);
	}

	union floating myf;
	myf.fnum = tmp;

	printf(" your input : %f\n", myf.fnum);

	// we  store [32bits    32<< |sign | exp | mant | >>0  ] ...
	if ( myf.bits.sign & 1<<0) printf("1"); //first we check  
	else printf("0");

	for (int i=1; i<9; i++){  //
		if ( i%4 ==0) printf(" ");
		if ( myf.bits.exp & 1<<(8-i)) printf("1");
		else printf("0");
	}
	for (int i=9; i<32; i++){
		if (i%4==0) printf(" ");
		if (myf.bits.mant & (1<<(31-i))) printf("1");
		else printf("0");
	}
	printf("\n");

}

int main(){
	printf("input [d,i] : ");
	char type[3];
	scanf("%s", type);

	if (type[0]=='i'){ //we are going to make float num from binary
		ftb();
	}
	else btf();
}
