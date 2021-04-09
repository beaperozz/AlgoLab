#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ins_sort (char **a, int len){
int i, j;
char *k;
for (i=1; i<len; i++)  {k=a[i];
			j=i-1;
			while ((j>=0) && (strcmp(a[j], k)>0)){a[j+1]=a[j];
							 j--;
							}
			a[j+1]=k;	
				}

}


int main(){
int len;
scanf("%d", &len);

char **a=(char**)malloc(len*sizeof(char *));
int i;
for(i=0; i<len; i++){
		     a[i]=(char*)malloc(101*sizeof(char));
		     scanf("%s", a[i]);		}
ins_sort(a, len);

for (i=0; i<len; i++) printf("%s\n", a[i]);

return 0;
}
