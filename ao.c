#include <stdio.h>
#include <string.h>

int anagramma (unsigned char *s1, unsigned char *s2){
char a[256];
char b[256];
int i;
int lx=strlen(s1);
int ly=strlen(s2);

if (ly!=lx) return 0;

for(i=0; i<256; i++){ a[i]= b[i]=0;}


for (i=0; i<lx; i++){
		a[s1[i]] +=1;
		b[s2[i]] +=1;
			}
for (i=0; i<256; i++){
		if (a[i]!=b[i]) return 0;
			}

return 1;
}



int main(){
char s1[256];
char s2[256];
scanf("%s", s1);
scanf("%s", s2);
int a= anagramma (s1, s2);
printf("%d", a);

return 0;
}
