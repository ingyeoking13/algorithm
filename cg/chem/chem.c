#include <stdio.h>
#include <string.h>

// Please use the chemical symbols in the periodic table below when you solve this problem.


int main(void) {
char *arr[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr" };
int T, test_case;
char sen[50001];
int i, j;
int tf[50001];
setbuf(stdout, NULL);

scanf("%d", &T);
for (test_case = 0; test_case < T; test_case++)
{

// initializing
memset(tf, 0, sizeof(tf));
scanf("%s", sen);

tf[0]=1;

for (i=0;sen[i];i++)
	for (j=0;j<sizeof(arr)/sizeof(arr[0]);j++){
		if (sen[i]==arr[j][0]+'a'-'A' && !arr[j][1] ) 
		  tf[i+1]|=tf[i];	
		if ( sen[i+1] && sen[i]==arr[j][0]-'A'+'a' && sen[i+1]==arr[j][1] ) 
			tf[i+2]|=tf[i];
	}

printf("Case #%d\n", test_case + 1);
if (tf[i]) printf("YES\n");
else printf("NO\n");

}
return 0;
}

