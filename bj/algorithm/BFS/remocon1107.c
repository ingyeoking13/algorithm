#include <stdio.h>

int broken[10]={0};
int possible(int jump);
int main(){

	int channel, num; 
	int i, j, ans;

	scanf("%d %d", &channel, &num);
	for (i=0; i<num;i++) {
		scanf("%d", &j);
		broken[j]=1;
	}

	int keystroke = channel-100;
	if (keystroke < 0)
		keystroke = -keystroke;
	ans=keystroke;

	for (i=0; i<1000000; i++){
		int jump=i;
		int len=possible(jump);
		if (len >0){
			int press = jump - channel;
			if (press<0) press =-press;
			if (ans > len+ press)
				ans =len+press;
		}
	}
	printf("%d", ans);

}

int possible(int jump){
	if (jump==0){
		if (broken[0]) return 0;
		else return 1;
	}
	int len=0;
	while(jump>0){
		if (broken[jump%10]) return 0;
		len++;
		jump/=10;
	}
	return len;
}

