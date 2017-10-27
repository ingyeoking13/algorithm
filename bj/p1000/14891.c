#include <stdio.h>
#define chk dir==-1
int a[8],b[8],c[8],d[8], i=2, j=2, k=6, l=2, m=6, n=6;
void rotate(int wheel, int dir){
	if (wheel==1){
		if (chk) { if (++i>7) i=0; }
		else { if (--i<0) i=7; }
	}
	else if (wheel==2){
		if (chk) { if (++j>7) j=0; if (++k>7) k=0; }
		else { if (--j<0) j=7; if (--k<0) k=7; }
	}
	else if (wheel==3){
		if (chk) { if (++l>7) l=0; if (++m>7) m=0; }
		else { if (--l<0) l=7; if (--m<0) m=7; }
	}
	else{
		if (chk) { if (++n>7) n=0; }
		else { if (--n<0) n=7; }
	}
}
int main(){
	for (int q=0; q<8; q++) scanf("%1d", &a[q]); for (int q=0; q<8; q++) scanf("%1d", &b[q]);
	for (int q=0; q<8; q++) scanf("%1d", &c[q]); for (int q=0; q<8; q++) scanf("%1d", &d[q]);
	int T, ans=0; scanf("%d", &T);
	while(T--){
		int wheel, dir; scanf("%d %d", &wheel, &dir);

		if(wheel==1){
			if (a[i]!=b[k]){
			  if (b[j]!=c[m]) {
						if (c[l]!=d[n]) rotate(4, -dir);
					rotate(3, dir);
				}
				rotate(2, -dir); 
			}
		}
		else if(wheel==2){
			if (b[k]!=a[i]) rotate(1, -dir);
			if (b[j]!=c[m]){
				if (c[l]!=d[n]) rotate(4, dir);
			 	rotate(3, -dir);
			}	
		}
		else if (wheel==3){
			if (c[m]!=b[j]) {
				if (b[k]!=a[i]) rotate(1, dir);
				rotate(2, -dir);
			}
			if (c[l]!=d[n]) rotate(4, -dir);
		}
		else{
			if (d[n]!=c[l]){
				if (c[m]!=b[j]) {
					if (b[k]!=a[i]) rotate (1, -dir);
					rotate(2, dir);
				}
				rotate(3, -dir);
			}
		}
		rotate(wheel, dir);
	}
	if(a[i-2<0?i+6:i-2]==1) ans+=1; if(b[j-2<0?j+6:j-2]==1) ans+=2;
	if(c[l-2<0?l+6:l-2]==1) ans+=4; if(d[n+2>7?n-6:n+2]==1) ans+=8;
	printf("%d\n", ans);
}
